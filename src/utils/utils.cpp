#include "utils/utils.h"

namespace integrated_navigation {
    void ConvertLLAToENU(const Eigen::Vector3d& init_lla,
                         const Eigen::Vector3d& point_lla,
                         Eigen::Vector3d* point_enu,
                         std::vector<double>& M) {
        GeographicLib::LocalCartesian local_cartesian;
        local_cartesian.Reset(init_lla(0), init_lla(1), init_lla(2));
        local_cartesian.Forward(point_lla(0), point_lla(1), point_lla(2), point_enu->data()[0], point_enu->data()[1], point_enu->data()[2], M);
    }

    void ConvertENUToLLA(const Eigen::Vector3d& init_lla,
                         const Eigen::Vector3d& point_enu,
                         Eigen::Vector3d* point_lla) {
        GeographicLib::LocalCartesian local_cartesian;
        local_cartesian.Reset(init_lla(0), init_lla(1), init_lla(2));
        local_cartesian.Reverse(point_enu(0), point_enu(1), point_enu(2),
                                point_lla->data()[0], point_lla->data()[1], point_lla->data()[2]);
    }

    void PositionAndMatrixFromGeoLib(const Eigen::Vector3d& init_lla,
                                     const Eigen::Vector3d& lla,
                                     Eigen::Vector3d* position,
                                     Eigen::Matrix3d* M_ecef2enu){
        // Compute position residual.
        // Convert wgs84 to ENU frame.
        std::vector<double> M(9,0.);
        ConvertLLAToENU(init_lla, lla, position, M);

        // Rotation Matrix from ECEF to ENU
        double* data_array = M.data();
        *M_ecef2enu = Eigen::Map<Eigen::Matrix<double, 3, 3>>(data_array);
    }

    Eigen::Matrix3d hat(const Eigen::Vector3d& v) {
        Eigen::Matrix3d w;
        w <<  0.,   -v(2),  v(1),
                v(2),  0.,   -v(0),
                -v(1),  v(0),  0.;

        return w;
    }
}