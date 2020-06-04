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
    BTree<std::pair<int,int>, Train> btree;
    // FAILURE if train_id exists
    if (btree.exist(Hash().hash(train_id), btree_file)) {printf("-1\n"); return;}

    // Warning: it seems that there's CE in the `train_id` in the next line, but I failed to solve the problem after comparing it to `add_user()` in `UserController.cpp`
    Train todo_train(train_id, station_num, seat_num, stations[STATION_LEN], prices, start_time, travel_times, stopover_times, sale_date_begin, sale_date_end, type, 0, 0);
    btree.insert(Hash().hash(train_id), todo_train, btree_file, info_file);
    printf("0\n");
}

void TrainController::delete_train( const char train_id[] ) {
    BTree<std::pair<int,int>, Train> btree;
    // FAILURE if train_id doesn't exist
    if (!btree.exist(Hash().hash(train_id), btree_file)) {printf("-1\n"); return;}

    Train todo_train = btree.query(Hash().hash(train_id), btree_file, info_file);
    todo_train.deleted = 1;
    btree.insert(Hash().hash(train_id), todo_train, btree_file, info_file);
    printf("0\n");
}

void TrainController::load( Interface *ifs, const char *id_filename, const char *info_filename ) {
    interface = ifs;
    // Why so?
    info_file.open(info_filename);
    btree_file.open(id_filename);
    // info_file.open("train_info_unreleased");
    // btree_file.open("train_id_unreleased");
}

void TrainController::save() {
    info_file.close();
    btree_file.close();
}