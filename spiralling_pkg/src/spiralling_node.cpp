#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <cmath>

int main(int argc, char **argv)
{
    double i=0;
    rclcpp::init(argc, argv);
    
    auto node = rclcpp::Node::make_shared("spiralling_node");
    auto pub = node->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);
    rclcpp::WallRate loop_rate(10);



    while (rclcpp::ok())
    {
        auto cmd_msg = std::make_unique<geometry_msgs::msg::Twist>();
        //cmd_msg->linear.x = 0.05;
        cmd_msg->angular.z = 5;
        cmd_msg->linear.x = i;
        i+=0.05;

        pub->publish(std::move(cmd_msg));

        loop_rate.sleep();
        rclcpp::spin_some(node);
    }

    rclcpp::shutdown();
    return 0;
}

