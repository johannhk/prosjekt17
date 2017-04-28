;; Auto-generated. Do not edit!


(when (boundp 'estimate_interest::DirectionStatus)
  (if (not (find-package "ESTIMATE_INTEREST"))
    (make-package "ESTIMATE_INTEREST"))
  (shadow 'DirectionStatus (find-package "ESTIMATE_INTEREST")))
(unless (find-package "ESTIMATE_INTEREST::DIRECTIONSTATUS")
  (make-package "ESTIMATE_INTEREST::DIRECTIONSTATUS"))

(in-package "ROS")
;;//! \htmlinclude DirectionStatus.msg.html


(defclass estimate_interest::DirectionStatus
  :super ros::object
  :slots (_direction _interested ))

(defmethod estimate_interest::DirectionStatus
  (:init
   (&key
    ((:direction __direction) "")
    ((:interested __interested) nil)
    )
   (send-super :init)
   (setq _direction (string __direction))
   (setq _interested __interested)
   self)
  (:direction
   (&optional __direction)
   (if __direction (setq _direction __direction)) _direction)
  (:interested
   (&optional __interested)
   (if __interested (setq _interested __interested)) _interested)
  (:serialization-length
   ()
   (+
    ;; string _direction
    4 (length _direction)
    ;; bool _interested
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _direction
       (write-long (length _direction) s) (princ _direction s)
     ;; bool _interested
       (if _interested (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _direction
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _direction (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; bool _interested
     (setq _interested (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get estimate_interest::DirectionStatus :md5sum-) "a5dd941b461c18d19ca708608d53c0ad")
(setf (get estimate_interest::DirectionStatus :datatype-) "estimate_interest/DirectionStatus")
(setf (get estimate_interest::DirectionStatus :definition-)
      "string direction
bool interested
")



(provide :estimate_interest/DirectionStatus "a5dd941b461c18d19ca708608d53c0ad")


