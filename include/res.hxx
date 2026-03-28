#pragma once

extern char _binary_res_main_html_start[];
extern char _binary_res_main_html_end[];
unsigned int _binary_res_main_html_len =
    _binary_res_main_html_end - _binary_res_main_html_start;

extern char _binary_res_bootstrap_min_css_start[];
extern char _binary_res_bootstrap_min_css_end[];
unsigned int _binary_res_bootstrap_min_css_len = 
    _binary_res_bootstrap_min_css_end - _binary_res_bootstrap_min_css_start;

extern char _binary_res_bootstrap_min_js_start[];
extern char _binary_res_bootstrap_min_js_end[];
unsigned int _binary_res_bootstrap_min_js_len = 
    _binary_res_bootstrap_min_js_end - _binary_res_bootstrap_min_js_start;

extern char _binary_res_popper_min_js_start[];
extern char _binary_res_popper_min_js_end[];
unsigned int _binary_res_popper_min_js_len = 
    _binary_res_popper_min_js_end - _binary_res_popper_min_js_start;
