
int *hash(char *key) {
    if(strlen(key) < 33) {
        return (int *)(key);
    } else {
        return 0;
    }
}