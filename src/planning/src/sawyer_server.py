#!/usr/bin/env python
from geometry_msgs.msg import Twist
import numpy as np
import rospy
from std_srvs.srv import Empty
import sys
from planning.srv import enviro  # Service type
# from turtlesim.srv import TeleportAbsolute
from path_test import main #Link to Arm Movement
from moveit_msgs.msg import OrientationConstraint
from geometry_msgs.msg import PoseStamped
from path_planner import PathPlanner

name = ""
def sawyer_callback(request):
    ## rospy.wait_for_service('clear')
    # rospy.wait_for_service("/{}/teleport_absolute".format(name))
    ## clear_proxy = rospy.ServiceProxy('clear', Empty)
    # teleport_proxy = rospy.ServiceProxy(
    #     "/{}/teleport_absolute".format(name),
    #     TeleportAbsolute
    # )
    # pub = rospy.Publisher(
    #     "/{}/cmd_vel".format(name), Twist, queue_size=50)

    # Publish to cmd_vel at 5 Hz
    # rate = rospy.Rate(5)

    # Clear historical path traces
    rospy.loginfo("Got message request")
    list_obj = []
    end_goal = request.goal

    for i in range(len(request.name_obj)):

        size = np.array([request.sizex[i], request.sizey[i], request.sizez[i]])
        name = request.name_obj
        pos = PoseStamped()
        pos.header.frame_id = "base"
        pos.pose.position.x = request.obj_posx[i]
        pos.pose.position.y = request.obj_posy[i]
        pos.pose.position.z = request.obj_posz[i]
        pos.pose.orientation.x = request.obj_orientx[i]
        pos.pose.orientation.y = request.obj_orienty[i]
        pos.pose.orientation.z = request.obj_orientz[i]
        pos.pose.orientation.w = request.obj_orientw[i]
        # plan = planner.plan_to_pose(pos, [])

        list_obj.append((size, name, pos))
    #Create a path constraint for the arm
    #UNCOMMENT FOR THE ORIENTATION CONSTRAINTS PART
    #TODO: add conditional taken from srv msg
    orien_const = OrientationConstraint()
    orien_const.link_name = "right_gripper";
    orien_const.header.frame_id = "base";
    # orien_const.orientation
    # orien_const.orientation.x = 0.0
    orien_const.orientation.y = -1.0
    # orien_const.orientation.z = 0.0
    # orien_const.orientation.w = 0.0

    orien_const.absolute_x_axis_tolerance = 0.2;
    orien_const.absolute_y_axis_tolerance = 0.2;
    orien_const.absolute_z_axis_tolerance = 0.2;
    orien_const.weight = 1.0;


    #If down orientation is needed, constrain it
    if (request.orient):
        main(list_obj, end_goal, orien_const)
    else:
        main(list_obj, end_goal, None)

    # clear_proxy()
    # while not rospy.is_shutdown():
    #     pub.publish(cmd)  # Publish to cmd_vel
    #     rate.sleep()  # Sleep until 
    
    #New implementation with path_test call loop
    # while not rospy.is_shutdown():

    #     while not rospy.is_shutdown():
    #         pub.publish(cmd)  # Publish to cmd_vel
    #         rate.sleep()  # Sleep until 
    #         try:
    #             x, y, z = 0.8, 0.05, 0.07
    #             goal_1 = PoseStamped()
    #             goal_1.header.frame6                                              _id = "base"

    #             #x, y, and z position
    #             goal_1.pose.position.x = x
    #             goal_1.pose.position.y = y
    #             goal_1.pose.position.z = z

    #             #Orientation as a quaternion
    #             goal_1.pose.orientation.x = 0.0
    #             goal_1.pose.orientation.y = -1.0
    #             goal_1.pose.orientation.z = 0.0
    #             goal_1.pose.orientation.w = 0.0

    #             goal_1 = end_goal

    #             # Might have to edit this . . . 
    #             # plan = planner.plan_to_pose(goal_1, [orien_const])
    #             plan = planner.plan_to_pose(goal_1, [])
    #             # input("Press <Enter> to move the right arm to goal pose 1: ")
    #             # print("OG PLAN", plan, '\n\n\n')
    #             # print(plan[1])
    #             # if not planner.execute_plan(plan[1]): 
    #             if not controller.execute_plan(plan[1]):
    #                 raise Exception("Execution failed")
    #         except Exception as e:
    #             print(e)
    #             traceback.print_exc()
    #         else:
    #             break

    return "Finished executing pose"  # This line will never be reached

def sawyer_server():
    # Initialize the server node for turtle1
    rospy.init_node("sawyer_server")
    # Register service
    s = rospy.Service(
        "/sawyer_parms/enviro",  # Service name
        enviro,  # Service type
        sawyer_callback  # Service callback
    )
    rospy.loginfo('Running sawyer server...')
    rospy.spin() # Spin the node until Ctrl-C


if __name__ == '__main__':
    # name = "turtle1"
    # if len(sys.argv) == 2:
    #     name = sys.argv[1]
    sawyer_server()
