; Auto-generated. Do not edit!


(cl:in-package cyborg_controller-msg)


;//! \htmlinclude StateMachineActionGoal.msg.html

(cl:defclass <StateMachineActionGoal> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (goal_id
    :reader goal_id
    :initarg :goal_id
    :type actionlib_msgs-msg:GoalID
    :initform (cl:make-instance 'actionlib_msgs-msg:GoalID))
   (goal
    :reader goal
    :initarg :goal
    :type cyborg_controller-msg:StateMachineGoal
    :initform (cl:make-instance 'cyborg_controller-msg:StateMachineGoal)))
)

(cl:defclass StateMachineActionGoal (<StateMachineActionGoal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StateMachineActionGoal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StateMachineActionGoal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name cyborg_controller-msg:<StateMachineActionGoal> is deprecated: use cyborg_controller-msg:StateMachineActionGoal instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <StateMachineActionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cyborg_controller-msg:header-val is deprecated.  Use cyborg_controller-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'goal_id-val :lambda-list '(m))
(cl:defmethod goal_id-val ((m <StateMachineActionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cyborg_controller-msg:goal_id-val is deprecated.  Use cyborg_controller-msg:goal_id instead.")
  (goal_id m))

(cl:ensure-generic-function 'goal-val :lambda-list '(m))
(cl:defmethod goal-val ((m <StateMachineActionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cyborg_controller-msg:goal-val is deprecated.  Use cyborg_controller-msg:goal instead.")
  (goal m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StateMachineActionGoal>) ostream)
  "Serializes a message object of type '<StateMachineActionGoal>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'goal_id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'goal) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StateMachineActionGoal>) istream)
  "Deserializes a message object of type '<StateMachineActionGoal>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'goal_id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'goal) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StateMachineActionGoal>)))
  "Returns string type for a message object of type '<StateMachineActionGoal>"
  "cyborg_controller/StateMachineActionGoal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StateMachineActionGoal)))
  "Returns string type for a message object of type 'StateMachineActionGoal"
  "cyborg_controller/StateMachineActionGoal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StateMachineActionGoal>)))
  "Returns md5sum for a message object of type '<StateMachineActionGoal>"
  "d33cc3551fa471b293164f712da353ee")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StateMachineActionGoal)))
  "Returns md5sum for a message object of type 'StateMachineActionGoal"
  "d33cc3551fa471b293164f712da353ee")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StateMachineActionGoal>)))
  "Returns full string definition for message of type '<StateMachineActionGoal>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%Header header~%actionlib_msgs/GoalID goal_id~%StateMachineGoal goal~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: actionlib_msgs/GoalID~%# The stamp should store the time at which this goal was requested.~%# It is used by an action server when it tries to preempt all~%# goals that were requested before a certain time~%time stamp~%~%# The id provides a way to associate feedback and~%# result message with specific goal requests. The id~%# specified must be unique.~%string id~%~%~%================================================================================~%MSG: cyborg_controller/StateMachineGoal~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#goal definition~%string previous_state~%string event~%string current_state~%string order #valid is EXECUTE or CANCEL~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StateMachineActionGoal)))
  "Returns full string definition for message of type 'StateMachineActionGoal"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%Header header~%actionlib_msgs/GoalID goal_id~%StateMachineGoal goal~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: actionlib_msgs/GoalID~%# The stamp should store the time at which this goal was requested.~%# It is used by an action server when it tries to preempt all~%# goals that were requested before a certain time~%time stamp~%~%# The id provides a way to associate feedback and~%# result message with specific goal requests. The id~%# specified must be unique.~%string id~%~%~%================================================================================~%MSG: cyborg_controller/StateMachineGoal~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#goal definition~%string previous_state~%string event~%string current_state~%string order #valid is EXECUTE or CANCEL~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StateMachineActionGoal>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'goal_id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'goal))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StateMachineActionGoal>))
  "Converts a ROS message object to a list"
  (cl:list 'StateMachineActionGoal
    (cl:cons ':header (header msg))
    (cl:cons ':goal_id (goal_id msg))
    (cl:cons ':goal (goal msg))
))
