set(led_srcs "src/led.cpp")
set(light_src "src/light_strip.cpp")
set(client_tcp_src "src/tcp_client.cpp")

idf_component_register(SRCS "${led_srcs}"
                            "${light_src}"
                            "${client_tcp_src}"
                            "/home/ubuntu/tools/esp-idf/examples/common_components/led_strip/src/led_strip_rmt_ws2812.c"
                            "/home/ubuntu/tools/esp-idf/examples/common_components/protocol_examples_common/connect.c"
                       INCLUDE_DIRS 
                           "include"
                           "/home/ubuntu/tools/esp-idf/examples/common_components/led_strip/include"
                           "/home/ubuntu/tools/esp-idf/examples/common_components/protocol_examples_common/include"
                           "/home/ubuntu/tools/esp-idf/components/nvs_flash/include"
                           "/home/ubuntu/tools/esp-idf/components/spi_flash/sim/stubs/spi_flash"  

                      )
                           