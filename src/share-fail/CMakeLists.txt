add_definitions(-DTRANSLATION_DOMAIN=\"purpose_share_fail\")
add_share_plugin(sharefailplugin sharefailplugin.cpp)
target_link_libraries(sharefailplugin KF5::I18n)
