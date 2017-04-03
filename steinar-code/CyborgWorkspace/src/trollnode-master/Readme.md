# Trollnode
ROS package for communicating with the trollface over TCP. Link to wiki is [here](https://www.ntnu.no/wiki/display/cyborg/f.+Trollface). 

The Trollnode is made for [ROS Hydro](http://wiki.ros.org/hydro) on Ubuntu 12.04, and probably won't work on other setups. It is written in C++03, as that's what ROS Hydro uses, and trying to use something newer would most likely lead to compatibility problems or mess up Catkin. Use catkin_make to build it.

# ROS nodes
Three nodes have been created: 
* setExpression: Node that creates a TCP connection to the Trollface and sends facial expressions, looking directions and Text To Speech (TTS) messages. It requires the IP adress to the computer Hosting the Trollface.
* sendVideo: Node that sends video to the Trollface which it requires to make random movements. Can be set to either send images published by k2_client from the Kinect after resizing them, or capturing images from a local webcam.
* publishExpression: Testnode for publishing expressions to setExpression and example for how to publish messages to the Trollface.






