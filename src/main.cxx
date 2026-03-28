#include "webui.hpp"
#include "res.hxx"
#include <iostream>

int main()
{
    auto win = webui::window();
    std::string html_main(
        _binary_res_main_html_start, 
        _binary_res_main_html_len
    );
    // win.set_kiosk(true);

    win.show_browser(
        html_main,
        1
    );
    webui_wait();

    webui_clean();
    return 0;
}