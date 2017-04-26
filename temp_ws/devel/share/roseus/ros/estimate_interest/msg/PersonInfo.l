;; Auto-generated. Do not edit!


(when (boundp 'estimate_interest::PersonInfo)
  (if (not (find-package "ESTIMATE_INTEREST"))
    (make-package "ESTIMATE_INTEREST"))
  (shadow 'PersonInfo (find-package "ESTIMATE_INTEREST")))
(unless (find-package "ESTIMATE_INTEREST::PERSONINFO")
  (make-package "ESTIMATE_INTEREST::PERSONINFO"))

(in-package "ROS")
;;//! \htmlinclude PersonInfo.msg.html


(defclass estimate_interest::PersonInfo
  :super ros::object
  :slots (_id _timestamp _x _y _z ))

(defmethod estimate_interest::PersonInfo
  (:init
   (&key
    ((:id __id) 0)
    ((:timestamp __timestamp) (instance ros::time :init))
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:z __z) 0.0)
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _timestamp __timestamp)
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _z (float __z))
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:timestamp
   (&optional __timestamp)
   (if __timestamp (setq _timestamp __timestamp)) _timestamp)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:serialization-length
   ()
   (+
    ;; uint8 _id
    1
    ;; time _timestamp
    8
    ;; float64 _x
    8
    ;; float64 _y
    8
    ;; float64 _z
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _id
       (write-byte _id s)
     ;; time _timestamp
       (write-long (send _timestamp :sec) s) (write-long (send _timestamp :nsec) s)
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z
       (sys::poke _z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _id
     (setq _id (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; time _timestamp
     (send _timestamp :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _timestamp :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z
     (setq _z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get estimate_interest::PersonInfo :md5sum-) "995ca4e5dfc4608addcf503c50d9ac84")
(setf (get estimate_interest::PersonInfo :datatype-) "estimate_interest/PersonInfo")
(setf (get estimate_interest::PersonInfo :definition-)
      "uint8 id
time timestamp
float64 x
float64 y
float64 z
")



(provide :estimate_interest/PersonInfo "995ca4e5dfc4608addcf503c50d9ac84")


