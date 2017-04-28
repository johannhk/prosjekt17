; Auto-generated. Do not edit!


(cl:in-package estimate_interest-msg)


;//! \htmlinclude DirectionStatus.msg.html

(cl:defclass <DirectionStatus> (roslisp-msg-protocol:ros-message)
  ((direction
    :reader direction
    :initarg :direction
    :type cl:string
    :initform "")
   (interested
    :reader interested
    :initarg :interested
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass DirectionStatus (<DirectionStatus>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DirectionStatus>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DirectionStatus)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name estimate_interest-msg:<DirectionStatus> is deprecated: use estimate_interest-msg:DirectionStatus instead.")))

(cl:ensure-generic-function 'direction-val :lambda-list '(m))
(cl:defmethod direction-val ((m <DirectionStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate_interest-msg:direction-val is deprecated.  Use estimate_interest-msg:direction instead.")
  (direction m))

(cl:ensure-generic-function 'interested-val :lambda-list '(m))
(cl:defmethod interested-val ((m <DirectionStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate_interest-msg:interested-val is deprecated.  Use estimate_interest-msg:interested instead.")
  (interested m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DirectionStatus>) ostream)
  "Serializes a message object of type '<DirectionStatus>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'direction))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'direction))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'interested) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DirectionStatus>) istream)
  "Deserializes a message object of type '<DirectionStatus>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'direction) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'direction) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:slot-value msg 'interested) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DirectionStatus>)))
  "Returns string type for a message object of type '<DirectionStatus>"
  "estimate_interest/DirectionStatus")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DirectionStatus)))
  "Returns string type for a message object of type 'DirectionStatus"
  "estimate_interest/DirectionStatus")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DirectionStatus>)))
  "Returns md5sum for a message object of type '<DirectionStatus>"
  "a5dd941b461c18d19ca708608d53c0ad")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DirectionStatus)))
  "Returns md5sum for a message object of type 'DirectionStatus"
  "a5dd941b461c18d19ca708608d53c0ad")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DirectionStatus>)))
  "Returns full string definition for message of type '<DirectionStatus>"
  (cl:format cl:nil "string direction~%bool interested~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DirectionStatus)))
  "Returns full string definition for message of type 'DirectionStatus"
  (cl:format cl:nil "string direction~%bool interested~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DirectionStatus>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'direction))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DirectionStatus>))
  "Converts a ROS message object to a list"
  (cl:list 'DirectionStatus
    (cl:cons ':direction (direction msg))
    (cl:cons ':interested (interested msg))
))
