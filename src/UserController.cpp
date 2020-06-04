#include "includes.hpp"

// BTree named as `btree`
// the operating user named as `cur_user`
// the operated user named as `todo_user`

void UserController::add_user( const char cur_username[],
				               const char username[],
				               const char password[],
				               const char name[],
				               const char mail_addr[],
				               int privilege ) {
    BTree<std::pair<int,int>, User> btree;
    // FAILURE if cur_username doesn't exist or if username exists
    if (!btree.exist(Hash().hash(cur_username), btree_file)) {printf("-1\n"); return;}
    if ( btree.exist(Hash().hash(    username), btree_file)) {printf("-1\n"); return;}

    if (this->user_cnt == 0) {
        User todo_user(username, password, name, mail_addr, 10, user_cnt, 0, 0);
        btree.insert(Hash().hash(username), todo_user, btree_file, info_file);
    }
    else {
        User cur_user = btree.query(Hash().hash(cur_username), btree_file, info_file);
        if (cur_user.is_login && (cur_user.privilege > privilege)) {
            User todo_user(username, password, name, mail_addr, privilege, user_cnt, 0, 0);
            btree.insert(Hash().hash(username), todo_user, btree_file, info_file);
        }
        else {
            printf("-1\n");
            return;
        }
    }
    user_cnt++;
    printf("0\n");
    return;
}

void UserController::login( const char username[],
                            const char password[] ) {
    BTree<std::pair<int,int>, User> btree;
    // FAILURE if username doesn't exist
    if (!btree.exist(Hash().hash(username), btree_file)) {printf("-1\n"); return;}
    User todo_user = btree.query(Hash().hash(username), btree_file, info_file);

    if (strcmp(todo_user.password, password) == 0 && todo_user.is_login == 0) {
        todo_user.is_login = 1;
        btree.insert(Hash().hash(username), todo_user, btree_file, info_file);
        printf("0\n");
    }
    else {
        // FAILURE if password is wrong OR MULTIPLE LOGINS
        printf("-1\n");
    }
}

void UserController::logout( const char username[] ) {
    BTree<std::pair<int,int>, User> btree;
    // FAILURE if username doesn't exist
    if (!btree.exist(Hash().hash(username), btree_file)) {printf("-1\n"); return;}
    User todo_user = btree.query(Hash().hash(username), btree_file, info_file);

    if (todo_user.is_login == 1) {
        todo_user.is_login = 0;
        btree.insert(Hash().hash(username), todo_user, btree_file, info_file);
        printf("0\n");
    }
    else {
        // FAILURE if MULTIPLE LOGOUTS
        printf("-1\n");
    }
}

void UserController::query_profile( const char cur_username[],
                                    const char username[] ) {
    BTree<std::pair<int,int>, User> btree;
    // FAILURE if cur_username doesn't exist or username doesn't exist
    if (!btree.exist(Hash().hash(cur_username), btree_file)) {printf("-1\n"); return;}
    if (!btree.exist(Hash().hash(    username), btree_file)) {printf("-1\n"); return;}
    User cur_user  = btree.query(Hash().hash(cur_username), btree_file, info_file);
    User todo_user = btree.query(Hash().hash(username), btree_file, info_file);

    if (!cur_user.is_login) {printf("-1\n"); return;}
    if ((strcmp(cur_username, username) == 0) || (cur_user.privilege > todo_user.privilege)) {
        print_profile(username);
    }
    else {printf("-1\n");}
}

void UserController::modify_profile( const char cur_username[],
                                     const char username[],
                                     const char password[], // empty is ""
                                     const char name[], // empty is ""
                                     const char mail_addr[], // empty is ""
                                     int privilege ) { // empty is -1
    BTree<std::pair<int,int>, User> btree;
    // FAILURE if cur_username doesn't exist or username doesn't exist
    if (!btree.exist(Hash().hash(cur_username), btree_file)) {printf("-1\n"); return;}
    if (!btree.exist(Hash().hash(    username), btree_file)) {printf("-1\n"); return;}
    User cur_user  = btree.query(Hash().hash(cur_username), btree_file, info_file);
    User todo_user = btree.query(Hash().hash(username), btree_file, info_file);

    if (!cur_user.is_login) {printf("-1\n"); return;}
    if ((strcmp(cur_username, username) == 0) || (cur_user.privilege > todo_user.privilege)) {
        strcpy(todo_user.username, username);
        // WARNING: not quite sure with the following 4 lines
        if (strcmp(password, "") != 0) strcpy(todo_user.password, password);
        if (strcmp(name, "") != 0) strcpy(todo_user.name, name);
        if (strcmp(mail_addr, "") != 0) strcpy(todo_user.mail_addr, mail_addr);
        if (privilege != -1) todo_user.privilege = privilege;
    }
    else {printf("-1\n");}
}

void UserController::query_order( const char username[] ) {   
    BTree<std::pair<int,int>, User> btree;
    // FAILURE if username doesn't exist
    if (!btree.exist(Hash().hash(username), btree_file)) {printf("-1\n"); return;}
    
    print_order(username);
}

void UserController::load( Interface *ifs ) {
    interface = ifs;
    btree_file.open("user_btree");
    info_file.open("user_info");
}

void UserController::save() {
    btree_file.close();
    info_file.close();
}

void UserController::modify_order( const char username[], int order_id, Order order ) {
    // WARNING: no checking whether username or order exists
    BTree<std::pair<std::pair<int, int>, int>, Order> order_btree;
    std::pair<std::pair<int, int>, int> temp(Hash().hash(username), order_id);
    order_btree.insert(temp, order, interface->order_controller.btree_file, interface->order_controller.info_file);
}

Order UserController::get_order( const char username[], int order_id ) {
    // WARNING: no checking whether username or order exists
    BTree<std::pair<std::pair<int, int>, int>, Order> order_btree;
    std::pair<std::pair<int, int>, int> temp(Hash().hash(username), order_id);
    return order_btree.query(temp, interface->order_controller.btree_file, interface->order_controller.info_file);
}

void UserController::print_profile( const char username[] ) {
    // WARNING: no checking whether username exists
    BTree<std::pair<int,int>, User> btree;
    User todo_user = btree.query(Hash().hash(username), btree_file, info_file);
    
    printf("%s %s %s %d\n", username, todo_user.name, todo_user.mail_addr, todo_user.privilege);
}

void UserController::print_order( const char username[] ) {
    // WARNING: no checking whether username or order exists
    BTree<std::pair<std::pair<int, int>, int>, Order> order_btree;
    std::pair<std::pair<int, int>, int> tem_l(Hash().hash(username), 0);
    // WARNING: const `1e8` is the INF of order_id; it's not saved as a const
    std::pair<std::pair<int, int>, int> tem_r(Hash().hash(username), 1e8);
    std::pair<std::pair<std::pair<int, int>, int>, Order> *value;
    int cnt = order_btree.query_list(tem_l, tem_r, interface->order_controller.btree_file, interface->order_controller.info_file, value);
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; ++i) {
        Order todo_order = value->second;
        Time leaving_time, arriving_time;
        // [<STATUS>] <trainID> <FROM> <LEAVING_TIME> -> <TO> <ARRIVING_TIME> <PRICE> <NUM>
        switch (todo_order.status) {
            case STATUS_SUCCESS:
                printf("[SUCCESS]");
                break;
            case STATUS_PENDING:
                printf("[PENDING]");
                break;
            case STATUS_REFUNDED:
                printf("[REFUNDED]");
                break;
        }
        printf(" %s %s ", todo_order.train_id, todo_order.from);
        std::cout << leaving_time;
        printf(" -> %s ", todo_order.to);
        std::cout << arriving_time << ' ' << todo_order.price << ' ' << todo_order.num << std::endl;
    }
    delete [] value;
}

void UserController::add_order( const char username[], Order order ) {
    // WARNING: no checking whether username exists
    BTree<std::pair<std::pair<int, int>, int>, Order> order_btree;
    std::pair<std::pair<int, int>, int> temp(Hash().hash(username), order.order_id);
    order_btree.insert(temp, order, interface->order_controller.btree_file, interface->order_controller.info_file);
}