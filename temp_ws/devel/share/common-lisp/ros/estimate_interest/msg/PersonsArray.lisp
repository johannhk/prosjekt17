; Auto-generated. Do not edit!


(cl:in-package estimate_interest-msg)


;//! \htmlinclude PersonsArray.msg.html

(cl:defclass <PersonsArray> (roslisp-msg-protocol:ros-message)
  ((persons
    :reader persons
    :initarg :persons
    :type (cl:vector estimate_interest-msg:PersonInfo)
   :initform (cl:make-array 0 :element-type 'estimate_interest-msg:PersonInfo :initial-element (cl:make-instance 'estimate_interest-msg:PersonInfo))))
)

(cl:defclass PersonsArray (<PersonsArray>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PersonsArray>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PersonsArray)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name estimate_interest-msg:<PersonsArray> is deprecated: use estimate_interest-msg:PersonsArray instead.")))

(cl:ensure-generic-function 'persons-val :lambda-list '(m))
(cl:defmethod persons-val ((m <PersonsArray>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader estimate_interest-msg:persons-val is deprecated.  Use estimate_interest-msg:persons instead.")
  (persons m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PersonsArray>) ostream)
  "Serializes a message object of type '<PersonsArray>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'persons))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'persons))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PersonsArray>) istream)
  "Deserializes a message object of type '<PersonsArray>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'persons) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'persons)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'estimate_interest-msg:PersonInfo))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PersonsArray>)))
  "Returns string type for a message object of type '<PersonsArray>"
  "estimate_interest/PersonsArray")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PersonsArray)))
  "Returns string type for a message object of type 'PersonsArray"
  "estimate_interest/PersonsArray")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PersonsArray>)))
  "Returns md5sum for a message object of type '<PersonsArray>"
  "17dc4f3d71f5a82ce376e93eda1f9791")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PersonsArray)))
  "Returns md5sum for a message object of type 'PersonsArray"
  "17dc4f3d71f5a82ce376e93eda1f9791")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PersonsArray>)))
  "Returns full string definition for message of type '<PersonsArray>"
  (cl:format cl:nil "PersonInfo[] persons~%================================================================================~%MSG: estimate_interest/PersonInfo~%uint8 id~%time timestamp~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PersonsArray)))
  "Returns full string definition for message of type 'PersonsArray"
  (cl:format cl:nil "PersonInfo[] persons~%================================================================================~%MSG: estimate_interest/PersonInfo~%uint8 id~%time timestamp~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PersonsArray>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'persons) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PersonsArray>))
  "Converts a ROS message object to a list"
  (cl:list 'PersonsArray
    (cl:cons ':persons (persons msg))
))
