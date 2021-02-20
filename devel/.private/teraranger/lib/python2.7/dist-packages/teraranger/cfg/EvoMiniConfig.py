## *********************************************************
##
## File autogenerated for the teraranger package
## by the dynamic_reconfigure package.
## Please do not edit.
##
## ********************************************************/

from dynamic_reconfigure.encoding import extract_params

inf = float('inf')

config_description = {'upper': 'DEFAULT', 'lower': 'groups', 'srcline': 246, 'name': 'Default', 'parent': 0, 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'cstate': 'true', 'parentname': 'Default', 'class': 'DEFAULT', 'field': 'default', 'state': True, 'parentclass': '', 'groups': [], 'parameters': [{'srcline': 291, 'description': 'Set the pixel mode', 'max': 2, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'Pixel_mode', 'edit_method': "{'enum_description': 'Set the pixel mode', 'enum': [{'srcline': 8, 'description': 'Single-pixel mode', 'srcfile': '/home/safmc/catkin_ws/src/teraranger/cfg/EvoMini.cfg', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'Single_pixel'}, {'srcline': 9, 'description': 'Two-pixel mode', 'srcfile': '/home/safmc/catkin_ws/src/teraranger/cfg/EvoMini.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'Two_pixel'}, {'srcline': 10, 'description': 'Two-by-two-pixel mode', 'srcfile': '/home/safmc/catkin_ws/src/teraranger/cfg/EvoMini.cfg', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'Two_by_two_pixel'}]}", 'default': 0, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 291, 'description': 'Set the ranging mode', 'max': 1, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'Range_mode', 'edit_method': "{'enum_description': 'Set the ranging mode', 'enum': [{'srcline': 13, 'description': 'Long-range mode', 'srcfile': '/home/safmc/catkin_ws/src/teraranger/cfg/EvoMini.cfg', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'Long'}, {'srcline': 14, 'description': 'Short-range mode', 'srcfile': '/home/safmc/catkin_ws/src/teraranger/cfg/EvoMini.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'Short'}]}", 'default': 0, 'level': 1, 'min': 0, 'type': 'int'}], 'type': '', 'id': 0}

min = {}
max = {}
defaults = {}
level = {}
type = {}
all_level = 0

#def extract_params(config):
#    params = []
#    params.extend(config['parameters'])
#    for group in config['groups']:
#        params.extend(extract_params(group))
#    return params

for param in extract_params(config_description):
    min[param['name']] = param['min']
    max[param['name']] = param['max']
    defaults[param['name']] = param['default']
    level[param['name']] = param['level']
    type[param['name']] = param['type']
    all_level = all_level | param['level']

EvoMini_Single_pixel = 0
EvoMini_Two_pixel = 1
EvoMini_Two_by_two_pixel = 2
EvoMini_Long = 0
EvoMini_Short = 1