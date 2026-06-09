#include "custom_controller/custom_controller.hpp"


using namespace custom_controller;
using namespace controller_interface;
using namespace hardware_interface;
using namespace std;


CustomController::CustomController() : ControllerInterface() 
{} // end of "CustomController()"


// Typically this method is only for init params
CallbackReturn CustomController::on_init()
{
    try
    {
        // Create the parameter listener and get the parameters
        param_listener = make_shared<ParamListener>(get_node());
        params = param_listener->get_params();

        // You must compile first in order to use `params` properly
        // Simply access your params with `params.<my_param>`
    }
    catch (const exception& e)
    {
        fprintf(stderr, "Exception thrown during init stage with message: %s \n", e.what());
        return CallbackReturn::ERROR;
    }

    return CallbackReturn::SUCCESS;

} // end of "on_init()"


InterfaceConfiguration CustomController::command_interface_configuration() const
{
    vector<string> command_interfaces;

    // Command Interfaces are in the form:
    // <joint_name>/<interface_type>
    // Ex: front_left_wheel/velocity

    // Code here...
    
    return {interface_configuration_type::INDIVIDUAL, command_interfaces};

} // end of "command_interface_configuration()"


InterfaceConfiguration CustomController::state_interface_configuration() const
{
    vector<string> state_interfaces;

    // State Interfaces are in the form:
    // <joint_name>/<interface_type>
    // Ex: front_left_wheel/velocity

    // Code here...

    return {interface_configuration_type::INDIVIDUAL, state_interfaces};

} // end of "state_interface_configuration()"


// This method is for the main update loop
return_type CustomController::update(const rclcpp::Time& /* time */, const rclcpp::Duration& /* period */)
{
    // Code here...

    return return_type::OK;

} // end of update(const rclcpp::Time&, const rclcpp::Duration&)


// Typically stuff like creating subscribers and/or publishers
CallbackReturn CustomController::on_configure(const rclcpp_lifecycle::State& /* previous_state */)
{
    // Code here...

    return CallbackReturn::SUCCESS;
}


// Typically stuff like assigning LoanedCommandInterface or LoanedStateInterface
CallbackReturn CustomController::on_activate(const rclcpp_lifecycle::State& /* previous_state */)
{
    RCLCPP_INFO(get_node()->get_logger(), "Activating...");

    // Code goes here...

    RCLCPP_INFO(get_node()->get_logger(), "Activated!");

    return CallbackReturn::SUCCESS;
}


// Typically stuff like clearing vectors
CallbackReturn CustomController::on_deactivate(const rclcpp_lifecycle::State& /* previous_state */)
{
    RCLCPP_INFO(get_node()->get_logger(), "Deactivating...");

    // Code goes here...

    RCLCPP_INFO(get_node()->get_logger(), "Deactivated!");

    return CallbackReturn::SUCCESS;

} // end of "on_deactivate(const rclcpp_lifecycle::State&)"


CallbackReturn CustomController::on_cleanup(const rclcpp_lifecycle::State& /* previous_state */)
{
    return CallbackReturn::SUCCESS;

} // end of "on_cleanup(const rclcpp_lifecycle::State&)"


CallbackReturn CustomController::on_error(const rclcpp_lifecycle::State& /* previous_state */)
{
    return CallbackReturn::SUCCESS;

} // end of "on_error(const rclcpp_lifecycle::State&)"


CallbackReturn CustomController::on_shutdown(const rclcpp_lifecycle::State& /* previous_state */)
{
    return CallbackReturn::SUCCESS;

} // end of "on_shutdown(const rclcpp_lifecycle::State&)"


#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(
    custom_controller::CustomController,
    controller_interface::ControllerInterface
)