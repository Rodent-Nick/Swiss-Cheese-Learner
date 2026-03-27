#include "webui.hpp"
#include "res.hxx"
#include <iostream>

int main()
{
    auto win = webui::window();
    
    win.set_size(640, 480);
    win.bind("greet", [](webui::window::event* e){
        std::cout << "Hello there: " << e->get_string(0) <<std::endl;
    });

    win.show_browser(
        _binary_res_main_html_start,
        1
    );
    webui_wait();

    webui_clean();
    return 0;
}