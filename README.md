# safe-speed-neural-network (SSNN)
Neural network that maps the level of risk of a situation onto the appropriate car travelling speed.
## Repository Files
  1. SSNN.mx: Mathematica file of the SSNN. 
  2. SSNN.wlent: SSNN in the wlnet (Wolfram format).  
  3. SSNN_cpp.cc: C++ code implementing the SSNN as function.
  4. SSNN.json and SSNN.params: SSNN implementation in MXnet.
  5. ShowNetwork.nb: File for loading the network and view the static output.

## Network input output
The inputs of the network are represented using 6 separate neurons and identify the following quantities:
  1)  the speed of the vehicle,
  2)  the longitudinal free displacement between the pedestrian and the vehicle expressed in curvilinear coordinates,
  3)  the lateral free displacement between the pedestrian and the vehicle expressed in curvilinear coordinates,
  4)  the orientation of the pedestrian relative to the road (zero when walking in the same direction of traffic),
  5)  the speed of the pedestrian,
  6)  the requested cruising speed (RCS) of the vehicle,
  
The output of the network is represented by three neurons encoding the rewards of the three possible actions composing the action space {−1,0,1} of  the  network:  increase, decrease or keep the RCS unchanged.
