#include "mysqlstub.h"
#include <stdio.h>
int main(int argc, char ** argv) {

	printf("Initializing mysqlstub\n");
	mysqlstub_init_stub();

	printf("mysqlstub version = %s\n",mysqlstub_get_stub_version());

	printf("Initializing mysql library\n");
	mysqlstub_library_init(0,0,0);

	printf("Initializing mysql\n");
	MYSQL * mysql = mysqlstub_init(0);
	if(mysql == 0) {
		fprintf(stderr,"Could not initialize mysql\n");
	}

	printf("closing mysql\n");
	mysqlstub_close(mysql);
	printf("Finalizing mysql library\n");
	mysqlstub_library_end();

	printf("Finalizing mysqlstub\n");
	mysqlstub_end_stub();
	return 0;
}
