
(cl:in-package :asdf)

(defsystem "speech_processing-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Expression" :depends-on ("_package_Expression"))
    (:file "_package_Expression" :depends-on ("_package"))
  ))