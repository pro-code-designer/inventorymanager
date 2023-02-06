
#define USER_FILE_ADDR "users.dat"
#define PRODUCT_FILE_ADDR "product.dat"
#define LOG_FILE_ADDR "time.dat"


#define MAX_USERNAME_LENGTH 32
#define USERNAME_ID 0

#define MAX_PASSWORD_LENGTH 32
#define PASSWORD_ID 1

#define MAX_EMAIL_LENGTH 40
#define EMAIL_ID 2

#define MAX_NUMBER_LENGTH 32
#define NUMBER_ID 3

#define MAX_MELICODE_LENGTH 32
#define MELICODE_ID 4

#define MAX_FNAME_LENGTH 32
#define FNAME_ID 5

#define MAX_LNAME_LENGTH 32
#define LNAME_ID 6



#define MAX_KID_LENGTH 32
#define KID_ID 0

#define MAX_KNAME_LENGTH 32
#define KNAME_ID 1

#define MAX_KBRAND_LENGTH 32
#define KBRAND_ID 2

#define MAX_KMODEL_LENGTH 32
#define KMODEL_ID 3

#define MAX_KPRICE_LENGTH 32
#define KPRICE_ID 4

#define MAX_KBALANCE_LENGTH 32
#define KBALANCE_ID 5

#define MAX_KMORE_LENGTH 32
#define KMORE_ID 6




#define MAX_STINFO_LENGTH 32
#define MAX_TIME_LENGTH 32
#define LSIGN_IN 1
#define EDIT_PROF 2
#define NEW_PR 3
#define IN_BAL 4
#define DEC_BAL 5





struct Product {
    char id[MAX_KID_LENGTH];
    char name[MAX_KNAME_LENGTH];
    char brand[MAX_KBRAND_LENGTH];
    char model[MAX_KMODEL_LENGTH];
    char price[MAX_KPRICE_LENGTH];
    char balance[MAX_KBALANCE_LENGTH];
    char more_info[MAX_KMORE_LENGTH];
};

struct Node {
    struct Product product;
    struct Node* next;
};



struct st_user{
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char fname[MAX_FNAME_LENGTH];
    char lname[MAX_LNAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char melicode[MAX_MELICODE_LENGTH];
    char number[MAX_NUMBER_LENGTH];
};

struct st_log{
    char userid[32];
    char product_id[32];
    char act_id[32];
    char info[MAX_STINFO_LENGTH];
    char time[MAX_TIME_LENGTH];
};

struct Lnode {
    struct st_log log;
    struct Lnode* next;
};
