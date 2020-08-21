//
// Created by Gastone Pietro Rosati Papini on 2020-08-19.
//

template <int Nin, int Nout>
void linear(const double in[Nin],const double w[Nout][Nin],const double b[Nout], double out[Nout]){
    for(int j = 0 ; j < Nout; j++){
        out[j] = 0;
        for(int i = 0 ; i < Nin ; i++){
            out[j] += in[i]*w[j][i];
        }
        out[j] += b[j];
    }
}

template <int Nin, int Nout>
void linearSig(const double in[Nin],const double w[Nout][Nin],const double b[Nout], double out[Nout]){
    for(int j = 0 ; j < Nout; j++){
        out[j] = 0;
        for(int i = 0 ; i < Nin ; i++){
            out[j] += in[i]*w[j][i];
        }
        out[j] += b[j];
    }
    for(int j = 0 ; j < Nout; j++) {
        out[j] = 1 / (1 + exp(-out[j]));
    }
}

template <int Nin>
void elu(const double in[Nin], double out[Nin]){
    for(int i = 0; i < Nin ; i++ ){
        out[i] = (in[i] > 0 ? in[i] : 0)-(((exp(in[i])-1)*(-in[i] > 0 ? -in[i] : 0))/in[i]);
    }
}


double SSNN(const double ego_vel_v, const double ped_long_disp_qs, const double ped_lat_disp_ps, const double ped_angle_alpha, const double ped_vel_wt, const double ego_rcs_vt);