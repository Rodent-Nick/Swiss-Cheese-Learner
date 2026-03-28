#include "webui.hpp"
#include "res.hxx"
#include <iostream>
#include <unordered_map>
#include <utility>

std::unordered_map<std::string, std::pair<char*, unsigned int>> file_map;
std::unordered_map<std::string, std::string> mime_map;

void populate_map() {

    file_map["./bootstrap_min.js"] = {
        _binary_res_bootstrap_min_js_start,
        _binary_res_bootstrap_min_js_len
    };
    mime_map["./bootstrap_min.js"] = std::string("text/javascript");
    file_map["./bootstrap_min.css"] = {
        _binary_res_bootstrap_min_css_start,
        _binary_res_bootstrap_min_css_len
    };
    mime_map["./bootstrap_min.css"] = std::string("text/css");
    file_map["./popper_min.js"] = {
        _binary_res_popper_min_js_start,
        _binary_res_popper_min_js_len
    };
    mime_map["./popper_min.js"] = std::string("text/javascript");

    return;
}

const void* myHandler(const char* filename, int* length) {

    std::string fn(filename);
    auto it = file_map.find(fn);
    auto it_m = mime_map.find(fn);

    if (it == file_map.end()) {
        return nullptr;
    }

    std::string resp = std::string(
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: ");

    std::string cont(it->second.first, it->second.second);

    resp.append(it_m->second);
    resp.append("\r\n\r\n");
    resp.append(cont);

    *length = it->second.second;
    return resp.c_str();
}

int main()
{
    auto win = webui::window();
    std::string html_main(
        _binary_res_main_html_start, 
        _binary_res_main_html_len
    );
    populate_map();

    win.show_browser(
        html_main,
        1
    );
    win.set_file_handler(myHandler);
    webui_wait();

    webui_clean();
    return 0;
}