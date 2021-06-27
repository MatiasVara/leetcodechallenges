bool isNumber(char * s){
    int state = 0;
    while (1){
        switch (state)
        {
            case 0:
                if ((*s== '+') || (*s == '-')){
                    state = 1;
                } else if ((*s >= '0') && (*s <='9')){
                    state = 2;
                } else if (*s == '.'){
                    state = 3;
                } else {
                    return false;
                }
                break;
            case 1:
                if ((*s >= '0') && (*s <='9')){
                    state = 2;
                } else if (*s == '.') {
                    state = 3;
                } else {
                    return false;
                }
                break;
            case 2:
                if ((*s >= '0') && (*s <='9')){
                    state = 2; 
                } else if (*s == '.') {
                    state = 5;
                } else if ((*s == 'e') || (*s == 'E')){
                    state = 7;
                } else if (*s =='\0'){
                    return true;
                } else {
                    return false;
                }
                break;
            case 3:
                if ((*s >= '0') && (*s <='9')){
                    state = 4;
                } else {
                    return false;
                }
                break;
            case 4:
                if ((*s >= '0') && (*s <='9')){
                    state = 4;
                } else if (*s == '\0'){
                    return true;
                } else if ((*s =='e') || (*s == 'E')){
                    state = 7;
                } else {
                    return false;
                }
                break;
            case 5:
                if ((*s=='e') || (*s == 'E')){
                    state = 7;
                } else if ((*s >= '0') && (*s <='9')) {
                    state = 6;
                } else if (*s == '\0'){
                    return true;
                } else {
                    return false;
                }
                break;
            case 6:
                if ((*s >= '0') && (*s <='9')) {
                    state = 6;
                } else if (*s == '\0'){
                    return true;
                } else if ((*s=='e') || (*s == 'E')){
                    state = 7;
                } else {
                    return false;
                }
                break;
            case 7:
                if ((*s== '+') || (*s == '-')){
                    state = 8;
                } else if ((*s >= '0') && (*s <='9')) {
                    state = 9;
                } else {
                    return false;
                }
                break;
            case 8:
                if ((*s >= '0') && (*s <='9')){
                    state = 9;
                } else if (*s == '\0'){
                    return false;
                } else {
                    return false;
                }
                break;
            case 9:
                if ((*s >= '0') && (*s <='9')) {
                    state = 9;
                } else if (*s == '\0'){
                    return true;
                } else {
                    return false;
                }
                break;
            default:
                return false;
       }
       s += 1;
    }
}
