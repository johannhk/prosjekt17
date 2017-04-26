;; Auto-generated. Do not edit!


(when (boundp 'estimate_interest::PersonsArray)
  (if (not (find-package "ESTIMATE_INTEREST"))
    (make-package "ESTIMATE_INTEREST"))
  (shadow 'PersonsArray (find-package "ESTIMATE_INTEREST")))
(unless (find-package "ESTIMATE_INTEREST::PERSONSARRAY")
  (make-package "ESTIMATE_INTEREST::PERSONSARRAY"))

(in-package "ROS")
;;//! \htmlinclude PersonsArray.msg.html


(defclass estimate_interest::PersonsArray
  :super ros::object
  :slots (_persons ))

(defmethod estimate_interest::PersonsArray
  (:init
   (&key
    ((:persons __persons) (let (r) (dotimes (i 0) (push (instance estimate_interest::PersonInfo :init) r)) r))
    )
   (send-super :init)
   (setq _persons __persons)
   self)
  (:persons
   (&rest __persons)
   (if (keywordp (car __persons))
       (send* _persons __persons)
     (progn
       (if __persons (setq _persons (car __persons)))
       _persons)))
  (:serialization-length
   ()
   (+
    ;; estimate_interest/PersonInfo[] _persons
    (apply #'+ (send-all _persons :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; estimate_interest/PersonInfo[] _persons
     (write-long (length _persons) s)
     (dolist (elem _persons)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; estimate_interest/PersonInfo[] _persons
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _persons (let (r) (dotimes (i n) (push (instance estimate_interest::PersonInfo :init) r)) r))
     (dolist (elem- _persons)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get estimate_interest::PersonsArray :md5sum-) "17dc4f3d71f5a82ce376e93eda1f9791")
(setf (get estimate_interest::PersonsArray :datatype-) "estimate_interest/PersonsArray")
(setf (get estimate_interest::PersonsArray :definition-)
      "PersonInfo[] persons
================================================================================
MSG: estimate_interest/PersonInfo
uint8 id
time timestamp
float64 x
float64 y
float64 z
")



(provide :estimate_interest/PersonsArray "17dc4f3d71f5a82ce376e93eda1f9791")


