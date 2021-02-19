# safe-speed-neural-network (SSNN)
Neural network that maps the level of risk of a situation onto the appropriate car travelling speed.
## Repository Files
  1. SSNN.mx: Mathematica file of the SSNN. 
  2. SSNN.wlent: SSNN in the wlnet (Wolfram format).  
  3. SSNN_cpp.cc: C++ code implementing the SSNN as function.
  4. SSNN.json and SSNN.params: SSNN implementation in MXnet.
  5. ShowNetwork.nb: File for loading the network and view the static output.

## Safe Speed Neural Network input output
The inputs of the network are represented using 6 separate neurons and identify the following quantities:
  1)  the speed of the vehicle in metre per second, `ego_vel_v`;
  2)  the longitudinal free displacement between the pedestrian and the vehicle expressed in curvilinear coordinates in metre, `ped_long_disp_qs`;
  3)  the lateral free displacement between the pedestrian and the vehicle expressed in curvilinear coordinates in metre, `ped_lat_disp_ps`;
  4)  the orientation of the pedestrian relative to the road: zero when walking in the same direction of traffic, negative if he/she walks towards the road, positive if he/she walks away from the road (value between -\pi  and \pi), `ped_angle_alpha`;
  5)  the speed of the pedestrian in metre per second, `ped_vel_wt`;
  6)  the actual requested cruising speed (RCS) of the vehicle in metre per second, `ego_rcs_vt`.

The output of the network is represented by three neurons encoding the rewards of the three possible actions composing the action space {−1,0,1} of  the  network:  increase, decrease or keep the RCS unchanged.

## Safe Speed Neural Network C++ function
```
double SSNN(const double ego_vel_v, const double ped_long_disp_qs, const double ped_lat_disp_ps, const double ped_angle_alpha, const double ped_vel_wt, const double ego_rcs_vt)
```

The function take the network's parameters in order, and it returns the safe action requested {−1,0,1} (increase, decrease or keep the RCS unchanged).

## Safe Speed Neural Network with bisection algorithm C++ function
```
double SSNNB(const double ego_vel_v, const double ped_long_disp_qs, const double ped_lat_disp_ps, const double ped_angle_alpha, const double ped_vel_wt, const double ego_rcs_vt)
```

The function take the network's parameters in order, and it returns the safe speed given the context.
