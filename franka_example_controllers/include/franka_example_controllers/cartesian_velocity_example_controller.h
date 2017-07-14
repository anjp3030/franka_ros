#pragma once

#include <memory>

#include <controller_interface/multi_interface_controller.h>
#include <franka_hw/franka_cartesian_command_interface.h>
#include <hardware_interface/robot_hw.h>
#include <ros/time.h>
#include <ros/node_handle.h>

namespace franka_example_controllers {

class CartesianVelocityExampleController
    : public controller_interface::MultiInterfaceController<
          franka_hw::FrankaVelocityCartesianInterface> {
 public:
  CartesianVelocityExampleController();
  bool init(hardware_interface::RobotHW* robot_hardware,
            ros::NodeHandle& root_node_handle,
            ros::NodeHandle&);
  void update(const ros::Time&, const ros::Duration& period);
  void stopping(const ros::Time&);

 private:
  std::string arm_id_;
  franka_hw::FrankaVelocityCartesianInterface* velocity_cartesian_interface_;
  std::unique_ptr<franka_hw::FrankaCartesianVelocityHandle>
      velocity_cartesian_handle_;
  ros::Duration elapsed_time_;
};

}  // namespace franka_example_controllers
