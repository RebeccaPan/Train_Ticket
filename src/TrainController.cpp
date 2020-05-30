#include "includes.hpp"

void TrainController::add_train( const char train_id[],
                int station_num,
                int seat_num,
                const char stations[][STATION_LEN],
                int prices[],
                Time start_time,
                int travel_times[],
                int stopover_times[],
                Date sale_date_begin,
                Date sale_date_end,
                char type ) {
    // TODO
}

void TrainController::delete_train( const char train_id[] ) {
    // TODO
}

void TrainController::load( Interface *ifs, const char *id_filename, const char *info_filename ) {
    interface = ifs;
    info_file.open("train_info_unreleased");
    btree_file.open("train_id_unreleased");
}

void TrainController::save() {
    info_file.close();
    btree_file.close();
}