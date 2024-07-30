#include <hmcl_msgs/LaneArray.h>
#include <autoware_msgs/LaneArray.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h>
// Trial 1
// namespace Converter {
//   void ConvertHMLCLaneToAutowareLane(const hmcl_msgs::LaneArray& hmcl_lane, autoware_msgs::LaneArray& autoware_lane)
//   {
//     // Copy fields from hmcl_lane to autoware_lane
//     // Example:
//     // autoware_lane.field1 = hmcl_lane.field1;
//     // autoware_lane.field2 = hmcl_lane.field2;
    
//     // Add your specific field mappings here
//     autoware_lane.id = hmcl_lane.id;
//     autoware_lane.lanes=hmcl_lane.lanes; 
//   }
// }

namespace Converter {
  void ConvertHMLCLaneArrayToAutowareLaneArray(const hmcl_msgs::LaneArray hmcl_lane_array, autoware_msgs::LaneArray autoware_lane_array)
  {
    // autoware_msgs::LaneArray autoware_lane;
    // autoware_lane.lanes=hmcl_lane_array.lanes
    // autoware_lane_array.lanes.push_back(autoware_lane_array.lanes)
    //Trial2

    for (auto hmcl_lane : hmcl_lane_array.lanes)
    {
        autoware_msgs::Lane autoware_lane;
        autoware_lane.header=hmcl_lane.header;
        autoware_lane.lane_id=hmcl_lane.lane_id;
        for (auto hmcl_lane_waypoints : hmcl_lane.waypoints){
            autoware_msgs::Waypoint autoware_lane_waypoints;
            autoware_lane_waypoints.gid=hmcl_lane_waypoints.gid;
            autoware_lane_waypoints.lid=hmcl_lane_waypoints.lid;
            autoware_lane_waypoints.pose=hmcl_lane_waypoints.pose;
            autoware_lane_waypoints.twist=hmcl_lane_waypoints.twist;
            autoware_lane_waypoints.lane_id=hmcl_lane_waypoints.lane_id;
        }
        // autoware_lane.lane_index=hmcl_lane.lane_index;
        // autoware_lane.cost=hmcl_lane.cost;
        // autoware_lane.closest_object_distance=hmcl_lane.closest_object_distance;
        // autoware_lane.closest_object_velocity=hmcl_lane.closest_object_velocity;
        // autoware_lane.is_blocked=hmcl_lane.is_blocked;
    
    //   auto med;
    //   med=hmcl_lane;
     // Example of copying a field, adjust as necessary
      // Add more field mappings as needed

      autoware_lane_array.lanes.emplace_back(autoware_lane);
    }
  }
  void ConvertAutowareLaneArrayToHMCLLaneArray(const hmcl_msgs::LaneArray hmcl_lane_array, autoware_msgs::LaneArray autoware_lane_array)
  {
    
    // hmcl_msgs::LaneArray hmcl_lane;
    // hmcl_lane.lanes=autoware_lane_array.lanes
    // hmcl_lane_array.lanes.push_back(hmcl_lane_array.lanes)
    // Trial2
    for (auto autoware_lane : autoware_lane_array.lanes)
    {
        hmcl_msgs::Lane hmcl_lane;
        hmcl_lane.header=autoware_lane.header;
        hmcl_lane.lane_id=autoware_lane.lane_id;
        for (auto autoware_lane_waypoints : autoware_lane.waypoints){
            hmcl_msgs::Waypoint hmcl_lane_waypoints;
            hmcl_lane_waypoints.gid=autoware_lane_waypoints.gid;
            hmcl_lane_waypoints.lid=autoware_lane_waypoints.lid;
            hmcl_lane_waypoints.pose=autoware_lane_waypoints.pose;
            hmcl_lane_waypoints.twist=autoware_lane_waypoints.twist;
            hmcl_lane_waypoints.lane_id=autoware_lane_waypoints.lane_id;
        }
        // hmcl_lane.lane_index=autoware_lane.lane_index;
        // hmcl_lane.cost=autoware_lane.cost;
        // hmcl_lane.closest_object_distance=autoware_lane.closest_object_distance;
        // hmcl_lane.closest_object_velocity=autoware_lane.closest_object_velocity;
        // hmcl_lane.is_blocked=autoware_lane.is_blocked;
    
    //   auto med;
    //   med=hmcl_lane;
     // Example of copying a field, adjust as necessary
      // Add more field mappings as needed

      autoware_lane_array.lanes.emplace_back(autoware_lane);
    }
  }
}