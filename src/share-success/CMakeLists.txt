add_definitions(-DTRANSLATION_DOMAIN=\"purpose_share_success\")
add_share_plugin(sharesuccessplugin sharesuccessplugin.cpp)
target_link_libraries(sharesuccessplugin KF5::I18n)
