;; Auto-generated. Do not edit!


(when (boundp 'trollnode::Expression)
  (if (not (find-package "TROLLNODE"))
    (make-package "TROLLNODE"))
  (shadow 'Expression (find-package "TROLLNODE")))
(unless (find-package "TROLLNODE::EXPRESSION")
  (make-package "TROLLNODE::EXPRESSION"))

(in-package "ROS")
;;//! \htmlinclude Expression.msg.html


(defclass trollnode::Expression
  :super ros::object
  :slots (_speech _expression _look ))

(defmethod trollnode::Expression
  (:init
   (&key
    ((:speech __speech) "")
    ((:expression __expression) "")
    ((:look __look) "")
    )
   (send-super :init)
   (setq _speech (string __speech))
   (setq _expression (string __expression))
   (setq _look (string __look))
   self)
  (:speech
   (&optional __speech)
   (if __speech (setq _speech __speech)) _speech)
  (:expression
   (&optional __expression)
   (if __expression (setq _expression __expression)) _expression)
  (:look
   (&optional __look)
   (if __look (setq _look __look)) _look)
  (:serialization-length
   ()
   (+
    ;; string _speech
    4 (length _speech)
    ;; string _expression
    4 (length _expression)
    ;; string _look
    4 (length _look)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _speech
       (write-long (length _speech) s) (princ _speech s)
     ;; string _expression
       (write-long (length _expression) s) (princ _expression s)
     ;; string _look
       (write-long (length _look) s) (princ _look s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _speech
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _speech (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _expression
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _expression (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _look
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _look (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get trollnode::Expression :md5sum-) "c4b0b66f4e8edc3a85581ccec469d88c")
(setf (get trollnode::Expression :datatype-) "trollnode/Expression")
(setf (get trollnode::Expression :definition-)
      "string speech		#The troll will say this out loud. Write normal english.
string expression 	#shortform for the expression, like angry, smile, etc. 
string look			#where the troll should look. left, right, up, down

")



(provide :trollnode/Expression "c4b0b66f4e8edc3a85581ccec469d88c")


