;; Auto-generated. Do not edit!


(when (boundp 'speech_processing::Expression)
  (if (not (find-package "SPEECH_PROCESSING"))
    (make-package "SPEECH_PROCESSING"))
  (shadow 'Expression (find-package "SPEECH_PROCESSING")))
(unless (find-package "SPEECH_PROCESSING::EXPRESSION")
  (make-package "SPEECH_PROCESSING::EXPRESSION"))

(in-package "ROS")
;;//! \htmlinclude Expression.msg.html


(defclass speech_processing::Expression
  :super ros::object
  :slots (_speech _expression ))

(defmethod speech_processing::Expression
  (:init
   (&key
    ((:speech __speech) "")
    ((:expression __expression) "")
    )
   (send-super :init)
   (setq _speech (string __speech))
   (setq _expression (string __expression))
   self)
  (:speech
   (&optional __speech)
   (if __speech (setq _speech __speech)) _speech)
  (:expression
   (&optional __expression)
   (if __expression (setq _expression __expression)) _expression)
  (:serialization-length
   ()
   (+
    ;; string _speech
    4 (length _speech)
    ;; string _expression
    4 (length _expression)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _speech
       (write-long (length _speech) s) (princ _speech s)
     ;; string _expression
       (write-long (length _expression) s) (princ _expression s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _speech
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _speech (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _expression
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _expression (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get speech_processing::Expression :md5sum-) "64c25de9407ff13a659a42faaadb6ea1")
(setf (get speech_processing::Expression :datatype-) "speech_processing/Expression")
(setf (get speech_processing::Expression :definition-)
      "string speech		#The troll will say this out loud. Write normal english.
string expression 	#shortform for the expression, like angry, smile, etc. 


")



(provide :speech_processing/Expression "64c25de9407ff13a659a42faaadb6ea1")


