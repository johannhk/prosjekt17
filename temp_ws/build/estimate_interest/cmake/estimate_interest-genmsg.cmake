# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "estimate_interest: 3 messages, 0 services")

set(MSG_I_FLAGS "-Iestimate_interest:/home/johs/prosjekt/temp_ws/src/estimate_interest/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(estimate_interest_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/DirectionStatus.msg" NAME_WE)
add_custom_target(_estimate_interest_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "estimate_interest" "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/DirectionStatus.msg" ""
)

get_filename_component(_filename "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonInfo.msg" NAME_WE)
add_custom_target(_estimate_interest_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "estimate_interest" "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonInfo.msg" ""
)

get_filename_component(_filename "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonsArray.msg" NAME_WE)
add_custom_target(_estimate_interest_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "estimate_interest" "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonsArray.msg" "estimate_interest/PersonInfo"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(estimate_interest
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/DirectionStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/estimate_interest
)
_generate_msg_cpp(estimate_interest
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonsArray.msg"
  "${MSG_I_FLAGS}"
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonInfo.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/estimate_interest
)
_generate_msg_cpp(estimate_interest
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/estimate_interest
)

### Generating Services

### Generating Module File
_generate_module_cpp(estimate_interest
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/estimate_interest
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(estimate_interest_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(estimate_interest_generate_messages estimate_interest_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/DirectionStatus.msg" NAME_WE)
add_dependencies(estimate_interest_generate_messages_cpp _estimate_interest_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonInfo.msg" NAME_WE)
add_dependencies(estimate_interest_generate_messages_cpp _estimate_interest_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonsArray.msg" NAME_WE)
add_dependencies(estimate_interest_generate_messages_cpp _estimate_interest_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(estimate_interest_gencpp)
add_dependencies(estimate_interest_gencpp estimate_interest_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS estimate_interest_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(estimate_interest
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/DirectionStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/estimate_interest
)
_generate_msg_eus(estimate_interest
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonsArray.msg"
  "${MSG_I_FLAGS}"
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonInfo.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/estimate_interest
)
_generate_msg_eus(estimate_interest
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/estimate_interest
)

### Generating Services

### Generating Module File
_generate_module_eus(estimate_interest
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/estimate_interest
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(estimate_interest_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(estimate_interest_generate_messages estimate_interest_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/DirectionStatus.msg" NAME_WE)
add_dependencies(estimate_interest_generate_messages_eus _estimate_interest_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonInfo.msg" NAME_WE)
add_dependencies(estimate_interest_generate_messages_eus _estimate_interest_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonsArray.msg" NAME_WE)
add_dependencies(estimate_interest_generate_messages_eus _estimate_interest_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(estimate_interest_geneus)
add_dependencies(estimate_interest_geneus estimate_interest_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS estimate_interest_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(estimate_interest
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/DirectionStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/estimate_interest
)
_generate_msg_lisp(estimate_interest
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonsArray.msg"
  "${MSG_I_FLAGS}"
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonInfo.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/estimate_interest
)
_generate_msg_lisp(estimate_interest
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/estimate_interest
)

### Generating Services

### Generating Module File
_generate_module_lisp(estimate_interest
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/estimate_interest
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(estimate_interest_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(estimate_interest_generate_messages estimate_interest_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/DirectionStatus.msg" NAME_WE)
add_dependencies(estimate_interest_generate_messages_lisp _estimate_interest_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonInfo.msg" NAME_WE)
add_dependencies(estimate_interest_generate_messages_lisp _estimate_interest_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonsArray.msg" NAME_WE)
add_dependencies(estimate_interest_generate_messages_lisp _estimate_interest_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(estimate_interest_genlisp)
add_dependencies(estimate_interest_genlisp estimate_interest_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS estimate_interest_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(estimate_interest
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/DirectionStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/estimate_interest
)
_generate_msg_nodejs(estimate_interest
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonsArray.msg"
  "${MSG_I_FLAGS}"
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonInfo.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/estimate_interest
)
_generate_msg_nodejs(estimate_interest
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/estimate_interest
)

### Generating Services

### Generating Module File
_generate_module_nodejs(estimate_interest
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/estimate_interest
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(estimate_interest_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(estimate_interest_generate_messages estimate_interest_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/DirectionStatus.msg" NAME_WE)
add_dependencies(estimate_interest_generate_messages_nodejs _estimate_interest_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonInfo.msg" NAME_WE)
add_dependencies(estimate_interest_generate_messages_nodejs _estimate_interest_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonsArray.msg" NAME_WE)
add_dependencies(estimate_interest_generate_messages_nodejs _estimate_interest_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(estimate_interest_gennodejs)
add_dependencies(estimate_interest_gennodejs estimate_interest_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS estimate_interest_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(estimate_interest
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/DirectionStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/estimate_interest
)
_generate_msg_py(estimate_interest
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonsArray.msg"
  "${MSG_I_FLAGS}"
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonInfo.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/estimate_interest
)
_generate_msg_py(estimate_interest
  "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/estimate_interest
)

### Generating Services

### Generating Module File
_generate_module_py(estimate_interest
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/estimate_interest
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(estimate_interest_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(estimate_interest_generate_messages estimate_interest_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/DirectionStatus.msg" NAME_WE)
add_dependencies(estimate_interest_generate_messages_py _estimate_interest_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonInfo.msg" NAME_WE)
add_dependencies(estimate_interest_generate_messages_py _estimate_interest_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/johs/prosjekt/temp_ws/src/estimate_interest/msg/PersonsArray.msg" NAME_WE)
add_dependencies(estimate_interest_generate_messages_py _estimate_interest_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(estimate_interest_genpy)
add_dependencies(estimate_interest_genpy estimate_interest_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS estimate_interest_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/estimate_interest)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/estimate_interest
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(estimate_interest_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/estimate_interest)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/estimate_interest
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(estimate_interest_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/estimate_interest)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/estimate_interest
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(estimate_interest_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/estimate_interest)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/estimate_interest
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(estimate_interest_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/estimate_interest)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/estimate_interest\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/estimate_interest
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(estimate_interest_generate_messages_py std_msgs_generate_messages_py)
endif()
