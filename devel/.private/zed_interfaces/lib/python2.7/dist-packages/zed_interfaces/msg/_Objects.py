# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from zed_interfaces/Objects.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg
import std_msgs.msg
import zed_interfaces.msg

class Objects(genpy.Message):
  _md5sum = "f74a9cc2a8c886c042be0d913eabb9fd"
  _type = "zed_interfaces/Objects"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """# Array of `object_stamped` topics
zed_interfaces/ObjectStamped[] objects

================================================================================
MSG: zed_interfaces/ObjectStamped
# Standard Header
Header header

# Object label
string label

# Object label ID
int16 label_id

# Object confidence level (1-99)
float32 confidence

# Object centroid
geometry_msgs/Point32 position

# Object velocity
geometry_msgs/Vector3 linear_vel

# Tracking state
# 0 -> OFF (object not valid)
# 1 -> OK
# 2 -> SEARCHING (occlusion occurred, trajectory is estimated)
int8 tracking_state 

# 2D Bounding box projected to Camera image
#      0 ------- 1
#      |         |
#      |         |
#      |         |
#      3 ------- 2
geometry_msgs/Point32[4] bbox_2d

# 3D Bounding box in world frame
#      1 ------- 2
#     /.        /|
#    0 ------- 3 |
#    | .       | |           
#    | 5.......| 6
#    |.        |/       
#    4 ------- 7
geometry_msgs/Point32[8] bbox_3d

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: geometry_msgs/Point32
# This contains the position of a point in free space(with 32 bits of precision).
# It is recommeded to use Point wherever possible instead of Point32.  
# 
# This recommendation is to promote interoperability.  
#
# This message is designed to take up less space when sending
# lots of points at once, as in the case of a PointCloud.  

float32 x
float32 y
float32 z
================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z"""
  __slots__ = ['objects']
  _slot_types = ['zed_interfaces/ObjectStamped[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       objects

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(Objects, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.objects is None:
        self.objects = []
    else:
      self.objects = []

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
      length = len(self.objects)
      buff.write(_struct_I.pack(length))
      for val1 in self.objects:
        _v1 = val1.header
        _x = _v1.seq
        buff.write(_get_struct_I().pack(_x))
        _v2 = _v1.stamp
        _x = _v2
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v1.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
        _x = val1.label
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
        _x = val1
        buff.write(_get_struct_hf().pack(_x.label_id, _x.confidence))
        _v3 = val1.position
        _x = _v3
        buff.write(_get_struct_3f().pack(_x.x, _x.y, _x.z))
        _v4 = val1.linear_vel
        _x = _v4
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _x = val1.tracking_state
        buff.write(_get_struct_b().pack(_x))
        if len(val1.bbox_2d) != 4:
          self._check_types(ValueError("Expecting %s items but found %s when writing '%s'" % (4, len(val1.bbox_2d), 'val1.bbox_2d')))
        for val2 in val1.bbox_2d:
          _x = val2
          buff.write(_get_struct_3f().pack(_x.x, _x.y, _x.z))
        if len(val1.bbox_3d) != 8:
          self._check_types(ValueError("Expecting %s items but found %s when writing '%s'" % (8, len(val1.bbox_3d), 'val1.bbox_3d')))
        for val2 in val1.bbox_3d:
          _x = val2
          buff.write(_get_struct_3f().pack(_x.x, _x.y, _x.z))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.objects is None:
        self.objects = None
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.objects = []
      for i in range(0, length):
        val1 = zed_interfaces.msg.ObjectStamped()
        _v5 = val1.header
        start = end
        end += 4
        (_v5.seq,) = _get_struct_I().unpack(str[start:end])
        _v6 = _v5.stamp
        _x = _v6
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v5.frame_id = str[start:end].decode('utf-8', 'rosmsg')
        else:
          _v5.frame_id = str[start:end]
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.label = str[start:end].decode('utf-8', 'rosmsg')
        else:
          val1.label = str[start:end]
        _x = val1
        start = end
        end += 6
        (_x.label_id, _x.confidence,) = _get_struct_hf().unpack(str[start:end])
        _v7 = val1.position
        _x = _v7
        start = end
        end += 12
        (_x.x, _x.y, _x.z,) = _get_struct_3f().unpack(str[start:end])
        _v8 = val1.linear_vel
        _x = _v8
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        start = end
        end += 1
        (val1.tracking_state,) = _get_struct_b().unpack(str[start:end])
        val1.bbox_2d = []
        for i in range(0, 4):
          val2 = geometry_msgs.msg.Point32()
          _x = val2
          start = end
          end += 12
          (_x.x, _x.y, _x.z,) = _get_struct_3f().unpack(str[start:end])
          val1.bbox_2d.append(val2)
        val1.bbox_3d = []
        for i in range(0, 8):
          val2 = geometry_msgs.msg.Point32()
          _x = val2
          start = end
          end += 12
          (_x.x, _x.y, _x.z,) = _get_struct_3f().unpack(str[start:end])
          val1.bbox_3d.append(val2)
        self.objects.append(val1)
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
      length = len(self.objects)
      buff.write(_struct_I.pack(length))
      for val1 in self.objects:
        _v9 = val1.header
        _x = _v9.seq
        buff.write(_get_struct_I().pack(_x))
        _v10 = _v9.stamp
        _x = _v10
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v9.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
        _x = val1.label
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
        _x = val1
        buff.write(_get_struct_hf().pack(_x.label_id, _x.confidence))
        _v11 = val1.position
        _x = _v11
        buff.write(_get_struct_3f().pack(_x.x, _x.y, _x.z))
        _v12 = val1.linear_vel
        _x = _v12
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _x = val1.tracking_state
        buff.write(_get_struct_b().pack(_x))
        if len(val1.bbox_2d) != 4:
          self._check_types(ValueError("Expecting %s items but found %s when writing '%s'" % (4, len(val1.bbox_2d), 'val1.bbox_2d')))
        for val2 in val1.bbox_2d:
          _x = val2
          buff.write(_get_struct_3f().pack(_x.x, _x.y, _x.z))
        if len(val1.bbox_3d) != 8:
          self._check_types(ValueError("Expecting %s items but found %s when writing '%s'" % (8, len(val1.bbox_3d), 'val1.bbox_3d')))
        for val2 in val1.bbox_3d:
          _x = val2
          buff.write(_get_struct_3f().pack(_x.x, _x.y, _x.z))
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
      if self.objects is None:
        self.objects = None
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.objects = []
      for i in range(0, length):
        val1 = zed_interfaces.msg.ObjectStamped()
        _v13 = val1.header
        start = end
        end += 4
        (_v13.seq,) = _get_struct_I().unpack(str[start:end])
        _v14 = _v13.stamp
        _x = _v14
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v13.frame_id = str[start:end].decode('utf-8', 'rosmsg')
        else:
          _v13.frame_id = str[start:end]
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.label = str[start:end].decode('utf-8', 'rosmsg')
        else:
          val1.label = str[start:end]
        _x = val1
        start = end
        end += 6
        (_x.label_id, _x.confidence,) = _get_struct_hf().unpack(str[start:end])
        _v15 = val1.position
        _x = _v15
        start = end
        end += 12
        (_x.x, _x.y, _x.z,) = _get_struct_3f().unpack(str[start:end])
        _v16 = val1.linear_vel
        _x = _v16
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        start = end
        end += 1
        (val1.tracking_state,) = _get_struct_b().unpack(str[start:end])
        val1.bbox_2d = []
        for i in range(0, 4):
          val2 = geometry_msgs.msg.Point32()
          _x = val2
          start = end
          end += 12
          (_x.x, _x.y, _x.z,) = _get_struct_3f().unpack(str[start:end])
          val1.bbox_2d.append(val2)
        val1.bbox_3d = []
        for i in range(0, 8):
          val2 = geometry_msgs.msg.Point32()
          _x = val2
          start = end
          end += 12
          (_x.x, _x.y, _x.z,) = _get_struct_3f().unpack(str[start:end])
          val1.bbox_3d.append(val2)
        self.objects.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2I = None
def _get_struct_2I():
    global _struct_2I
    if _struct_2I is None:
        _struct_2I = struct.Struct("<2I")
    return _struct_2I
_struct_3d = None
def _get_struct_3d():
    global _struct_3d
    if _struct_3d is None:
        _struct_3d = struct.Struct("<3d")
    return _struct_3d
_struct_3f = None
def _get_struct_3f():
    global _struct_3f
    if _struct_3f is None:
        _struct_3f = struct.Struct("<3f")
    return _struct_3f
_struct_b = None
def _get_struct_b():
    global _struct_b
    if _struct_b is None:
        _struct_b = struct.Struct("<b")
    return _struct_b
_struct_hf = None
def _get_struct_hf():
    global _struct_hf
    if _struct_hf is None:
        _struct_hf = struct.Struct("<hf")
    return _struct_hf
