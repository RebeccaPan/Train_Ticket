#include "includes.hpp"

void OrderController::load( Interface *ifs ) {
    interface = ifs;
    btree_file.open("order_btree");
    info_file.open("order_info");
}

void OrderController::save() {
    btree_file.close();
    info_file.close();
}