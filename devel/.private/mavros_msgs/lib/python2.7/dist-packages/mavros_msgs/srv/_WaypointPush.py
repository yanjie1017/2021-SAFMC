# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from mavros_msgs/WaypointPushRequest.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import mavros_msgs.msg

class WaypointPushRequest(genpy.Message):
  _md5sum = "c07581e03ec6aa8a9583354fd792c02f"
  _type = "mavros_msgs/WaypointPushRequest"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """# Send waypoints to device
#
#  :start_index: will define a partial waypoint update. Set to 0 for full update
#
# Returns success status and transfered count

uint16 start_index
mavros_msgs/Waypoint[] waypoints

================================================================================
MSG: mavros_msgs/Waypoint
# Waypoint.msg
#
# ROS representation of MAVLink MISSION_ITEM
# See mavlink documentation



# see enum MAV_FRAME
uint8 frame
uint8 FRAME_GLOBAL = 0
uint8 FRAME_LOCAL_NED = 1
uint8 FRAME_MISSION = 2
uint8 FRAME_GLOBAL_REL_ALT = 3
uint8 FRAME_LOCAL_ENU = 4

# see enum MAV_CMD and CommandCode.msg
uint16 command

bool is_current
bool autocontinue
# meaning of this params described in enum MAV_CMD
float32 param1
float32 param2
float32 param3
float32 param4
float64 x_lat
float64 y_long
float64 z_alt
"""
  __slots__ = ['start_index','waypoints']
  _slot_types = ['uint16','mavros_msgs/Waypoint[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       start_index,waypoints

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(WaypointPushRequest, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.start_index is None:
        self.start_index = 0
      if self.waypoints is None:
        self.waypoints = []
    else:
      self.start_index = 0
      self.waypoints = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self.start_index
      buff.write(_get_struct_H().pack(_x))
      length = len(self.waypoints)
      buff.write(_struct_I.pack(length))
      for val1 in self.waypoints:
        _x = val1
        buff.write(_get_struct_BH2B4f3d().pack(_x.frame, _x.command, _x.is_current, _x.autocontinue, _x.param1, _x.param2, _x.param3, _x.param4, _x.x_lat, _x.y_long, _x.z_alt))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.waypoints is None:
        self.waypoints = None
      end = 0
      start = end
      end += 2
      (self.start_index,) = _get_struct_H().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.waypoints = []
      for i in range(0, length):
        val1 = mavros_msgs.msg.Waypoint()
        _x = val1
        start = end
        end += 45
        (_x.frame, _x.command, _x.is_current, _x.autocontinue, _x.param1, _x.param2, _x.param3, _x.param4, _x.x_lat, _x.y_long, _x.z_alt,) = _get_struct_BH2B4f3d().unpack(str[start:end])
        val1.is_current = bool(val1.is_current)
        val1.autocontinue = bool(val1.autocontinue)
        self.waypoints.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self.start_index
      buff.write(_get_struct_H().pack(_x))
      length = len(self.waypoints)
      buff.write(_struct_I.pack(length))
      for val1 in self.waypoints:
        _x = val1
        buff.write(_get_struct_BH2B4f3d().pack(_x.frame, _x.command, _x.is_current, _x.autocontinue, _x.param1, _x.param2, _x.param3, _x.param4, _x.x_lat, _x.y_long, _x.z_alt))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.waypoints is None:
        self.waypoints = None
      end = 0
      start = end
      end += 2
      (self.start_index,) = _get_struct_H().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.waypoints = []
      for i in range(0, length):
        val1 = mavros_msgs.msg.Waypoint()
        _x = val1
        start = end
        end += 45
        (_x.frame, _x.command, _x.is_current, _x.autocontinue, _x.param1, _x.param2, _x.param3, _x.param4, _x.x_lat, _x.y_long, _x.z_alt,) = _get_struct_BH2B4f3d().unpack(str[start:end])
        val1.is_current = bool(val1.is_current)
        val1.autocontinue = bool(val1.autocontinue)
        self.waypoints.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_BH2B4f3d = None
def _get_struct_BH2B4f3d():
    global _struct_BH2B4f3d
    if _struct_BH2B4f3d is None:
        _struct_BH2B4f3d = struct.Struct("<BH2B4f3d")
    return _struct_BH2B4f3d
_struct_H = None
def _get_struct_H():
    global _struct_H
    if _struct_H is None:
        _struct_H = struct.Struct("<H")
    return _struct_H
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from mavros_msgs/WaypointPushResponse.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class WaypointPushResponse(genpy.Message):
  _md5sum = "90e0074a42480231d34eed864d14365e"
  _type = "mavros_msgs/WaypointPushResponse"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """bool success
uint32 wp_transfered

"""
  __slots__ = ['success','wp_transfered']
  _slot_types = ['bool','uint32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       success,wp_transfered

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(WaypointPushResponse, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.success is None:
        self.success = False
      if self.wp_transfered is None:
        self.wp_transfered = 0
    else:
      self.success = False
      self.wp_transfered = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_BI().pack(_x.success, _x.wp_transfered))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 5
      (_x.success, _x.wp_transfered,) = _get_struct_BI().unpack(str[start:end])
      self.success = bool(self.success)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_BI().pack(_x.success, _x.wp_transfered))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 5
      (_x.success, _x.wp_transfered,) = _get_struct_BI().unpack(str[start:end])
      self.success = bool(self.success)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_BI = None
def _get_struct_BI():
    global _struct_BI
    if _struct_BI is None:
        _struct_BI = struct.Struct("<BI")
    return _struct_BI
class WaypointPush(object):
  _type          = 'mavros_msgs/WaypointPush'
  _md5sum = '5b2bca74e830798e1579b58cafd50527'
  _request_class  = WaypointPushRequest
  _response_class = WaypointPushResponse
