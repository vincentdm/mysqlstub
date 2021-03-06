#include "mysqlstub_private.h"
#include "config.h"
#include "ltdl.h"
#include <stdio.h>

static int mysqlstub_inited = 0;
static int ltdl=0;
static lt_dlhandle module;


const char * mysqlstub_get_stub_version() {
	return PACKAGE_VERSION;
}


static mysqlstub_server_init_t * mysqlstub_server_init_ptr = NULL;
static mysqlstub_server_end_t * mysqlstub_server_end_ptr = NULL;


static mysqlstub_get_parameters_t * mysqlstub_get_parameters_ptr = NULL;

static mysqlstub_thread_init_t * mysqlstub_thread_init_ptr = NULL;
static mysqlstub_thread_end_t * mysqlstub_thread_end_ptr = NULL;


static mysqlstub_num_rows_t * mysqlstub_num_rows_ptr = NULL;
static mysqlstub_num_fields_t * mysqlstub_num_fields_ptr = NULL;
static mysqlstub_eof_t * mysqlstub_eof_ptr = NULL;
static mysqlstub_fetch_field_direct_t * mysqlstub_fetch_field_direct_ptr = NULL;
static mysqlstub_fetch_fields_t * mysqlstub_fetch_fields_ptr = NULL;
static mysqlstub_row_tell_t * mysqlstub_row_tell_ptr = NULL;
static mysqlstub_field_tell_t * mysqlstub_field_tell_ptr = NULL;

static mysqlstub_field_count_t * mysqlstub_field_count_ptr = NULL;
static mysqlstub_affected_rows_t * mysqlstub_affected_rows_ptr = NULL;
static mysqlstub_insert_id_t * mysqlstub_insert_id_ptr = NULL;
static mysqlstub_errno_t * mysqlstub_errno_ptr = NULL;
static mysqlstub_error_t * mysqlstub_error_ptr = NULL;
static mysqlstub_sqlstate_t * mysqlstub_sqlstate_ptr = NULL;
static mysqlstub_warning_count_t * mysqlstub_warning_count_ptr = NULL;
static mysqlstub_info_t * mysqlstub_info_ptr = NULL;
static mysqlstub_thread_id_t * mysqlstub_thread_id_ptr = NULL;
static mysqlstub_character_set_name_t * mysqlstub_character_set_name_ptr = NULL;
static mysqlstub_set_character_set_t * mysqlstub_set_character_set_ptr = NULL;

static mysqlstub_init_t * mysqlstub_init_ptr = NULL;
static mysqlstub_ssl_set_t * mysqlstub_ssl_set_ptr = NULL;
static mysqlstub_get_ssl_cipher_t * mysqlstub_get_ssl_cipher_ptr = NULL;
static mysqlstub_change_user_t * mysqlstub_change_user_ptr = NULL;
static mysqlstub_real_connect_t * mysqlstub_real_connect_ptr = NULL;
static mysqlstub_select_db_t * mysqlstub_select_db_ptr = NULL;
static mysqlstub_query_t * mysqlstub_query_ptr = NULL;
static mysqlstub_send_query_t * mysqlstub_send_query_ptr = NULL;
static mysqlstub_real_query_t * mysqlstub_real_query_ptr = NULL;
static mysqlstub_store_result_t * mysqlstub_store_result_ptr = NULL;
static mysqlstub_use_result_t * mysqlstub_use_result_ptr = NULL;

static mysqlstub_get_character_set_info_t * mysqlstub_get_character_set_info_ptr = NULL;


static mysqlstub_shutdown_t * mysqlstub_shutdown_ptr = NULL;
static mysqlstub_dump_debug_info_t * mysqlstub_dump_debug_info_ptr = NULL;
static mysqlstub_refresh_t * mysqlstub_refresh_ptr = NULL;
static mysqlstub_kill_t * mysqlstub_kill_ptr = NULL;
static mysqlstub_set_server_option_t * mysqlstub_set_server_option_ptr = NULL;
static mysqlstub_ping_t * mysqlstub_ping_ptr = NULL;
static mysqlstub_stat_t * mysqlstub_stat_ptr = NULL;
static mysqlstub_get_server_info_t * mysqlstub_get_server_info_ptr = NULL;
static mysqlstub_get_client_info_t * mysqlstub_get_client_info_ptr = NULL;
static mysqlstub_get_client_version_t * mysqlstub_get_client_version_ptr = NULL;
static mysqlstub_get_host_info_t * mysqlstub_get_host_info_ptr = NULL;
static mysqlstub_get_server_version_t * mysqlstub_get_server_version_ptr = NULL;
static mysqlstub_get_proto_info_t * mysqlstub_get_proto_info_ptr = NULL;
static mysqlstub_list_dbs_t * mysqlstub_list_dbs_ptr = NULL;
static mysqlstub_list_tables_t * mysqlstub_list_tables_ptr = NULL;
static mysqlstub_list_processes_t * mysqlstub_list_processes_ptr = NULL;
static mysqlstub_options_t * mysqlstub_options_ptr = NULL;
static mysqlstub_free_result_t * mysqlstub_free_result_ptr = NULL;
static mysqlstub_data_seek_t * mysqlstub_data_seek_ptr = NULL;
static mysqlstub_row_seek_t * mysqlstub_row_seek_ptr = NULL;
static mysqlstub_field_seek_t * mysqlstub_field_seek_ptr = NULL;
static mysqlstub_fetch_row_t * mysqlstub_fetch_row_ptr = NULL;
static mysqlstub_fetch_lengths_t * mysqlstub_fetch_lengths_ptr = NULL;
static mysqlstub_fetch_field_t * mysqlstub_fetch_field_ptr = NULL;
static mysqlstub_list_fields_t * mysqlstub_list_fields_ptr = NULL;
static mysqlstub_escape_string_t * mysqlstub_escape_string_ptr = NULL;
static mysqlstub_hex_string_t * mysqlstub_hex_string_ptr = NULL;
static mysqlstub_real_escape_string_t * mysqlstub_real_escape_string_ptr = NULL;
static mysqlstub_debug_t * mysqlstub_debug_ptr = NULL;
static mysqlstub_thread_safe_t * mysqlstub_thread_safe_ptr = NULL;
static mysqlstub_embedded_t * mysqlstub_embedded_ptr = NULL;
static mysqlstub_read_query_result_t * mysqlstub_read_query_result_ptr = NULL;


static mysqlstub_stmt_init_t * mysqlstub_stmt_init_ptr = NULL;
static mysqlstub_stmt_prepare_t * mysqlstub_stmt_prepare_ptr = NULL;
static mysqlstub_stmt_execute_t * mysqlstub_stmt_execute_ptr = NULL;
static mysqlstub_stmt_fetch_t * mysqlstub_stmt_fetch_ptr = NULL;
static mysqlstub_stmt_fetch_column_t * mysqlstub_stmt_fetch_column_ptr = NULL;
static mysqlstub_stmt_store_result_t * mysqlstub_stmt_store_result_ptr = NULL;
static mysqlstub_stmt_param_count_t * mysqlstub_stmt_param_count_ptr = NULL;
static mysqlstub_stmt_attr_set_t * mysqlstub_stmt_attr_set_ptr = NULL;
static mysqlstub_stmt_attr_get_t * mysqlstub_stmt_attr_get_ptr = NULL;
static mysqlstub_stmt_bind_param_t * mysqlstub_stmt_bind_param_ptr = NULL;
static mysqlstub_stmt_bind_result_t * mysqlstub_stmt_bind_result_ptr = NULL;
static mysqlstub_stmt_close_t * mysqlstub_stmt_close_ptr = NULL;
static mysqlstub_stmt_reset_t * mysqlstub_stmt_reset_ptr = NULL;
static mysqlstub_stmt_free_result_t * mysqlstub_stmt_free_result_ptr = NULL;
static mysqlstub_stmt_send_long_data_t * mysqlstub_stmt_send_long_data_ptr = NULL;
static mysqlstub_stmt_param_metadata_t * mysqlstub_stmt_result_metadata_ptr = NULL;
static mysqlstub_stmt_param_metadata_t * mysqlstub_stmt_param_metadata_ptr = NULL;
static mysqlstub_stmt_errno_t * mysqlstub_stmt_errno_ptr = NULL;
static mysqlstub_stmt_error_t * mysqlstub_stmt_error_ptr = NULL;
static mysqlstub_stmt_sqlstate_t * mysqlstub_stmt_sqlstate_ptr = NULL;
static mysqlstub_stmt_row_seek_t * mysqlstub_stmt_row_seek_ptr = NULL;
static mysqlstub_stmt_row_tell_t * mysqlstub_stmt_row_tell_ptr = NULL;
static mysqlstub_stmt_data_seek_t * mysqlstub_stmt_data_seek_ptr = NULL;
static mysqlstub_stmt_num_rows_t * mysqlstub_stmt_num_rows_ptr = NULL;
static mysqlstub_stmt_affected_rows_t * mysqlstub_stmt_affected_rows_ptr = NULL;
static mysqlstub_stmt_insert_id_t * mysqlstub_stmt_insert_id_ptr = NULL;
static mysqlstub_stmt_field_count_t * mysqlstub_stmt_field_count_ptr = NULL;

static mysqlstub_commit_t * mysqlstub_commit_ptr = NULL;
static mysqlstub_rollback_t * mysqlstub_rollback_ptr = NULL;
static mysqlstub_autocommit_t * mysqlstub_autocommit_ptr = NULL;
static mysqlstub_more_results_t * mysqlstub_more_results_ptr = NULL;
static mysqlstub_next_result_t * mysqlstub_next_result_ptr = NULL;
static mysqlstub_stmt_next_result_t * mysqlstub_stmt_next_result_ptr = NULL;
static mysqlstub_close_t * mysqlstub_close_ptr = NULL;


static _mysqlstub_warning(const char * str) {
	fprintf(stderr,"%s: WARNING: %s",PACKAGE_NAME,str);
}

static _mysqlstub_error(const char * str) {
	fprintf(stderr,"%s: ERROR: %s",PACKAGE_NAME,str);
}

int mysqlstub_init_stub() {
	if (mysqlstub_inited != 0)
		return 0;

	LTDL_SET_PRELOADED_SYMBOLS();
	ltdl = lt_dlinit();
	if(!ltdl) {

#ifdef __linux__

		//check libmysqlclient.so
		module = lt_dlopen("libmysqlclient.so");
		if(module == 0) {
			_mysqlstub_error(lt_dlerror());
		}

#else
#error platform not supported yet!
#endif

		if(module != 0) {
			//use lt_dlsym(module,name) to bind module functions
			mysqlstub_server_init_ptr = lt_dlsym(module,"mysql_server_init");
			if (!mysqlstub_server_init_ptr) {
				_mysqlstub_warning("Could not load \"mysql_server_init\"\n");
			}

			mysqlstub_server_end_ptr = lt_dlsym(module,"mysql_server_end");
			mysqlstub_get_parameters_ptr = lt_dlsym(module,"mysql_get_parameters");

			mysqlstub_thread_init_ptr = lt_dlsym(module,"mysql_thread_init");
			mysqlstub_thread_end_ptr = lt_dlsym(module,"mysql_thread_end");


			mysqlstub_num_rows_ptr = lt_dlsym(module,"mysql_num_rows");
			mysqlstub_num_fields_ptr = lt_dlsym(module,"mysql_num_fields");
			mysqlstub_eof_ptr = lt_dlsym(module,"mysql_eof_ptr");
			mysqlstub_fetch_field_direct_ptr = lt_dlsym(module,"mysql_fetch_field_direct");
			mysqlstub_fetch_fields_ptr = lt_dlsym(module,"mysql_fetch_fields");
			mysqlstub_row_tell_ptr = lt_dlsym(module,"mysql_row_tell");
			mysqlstub_field_tell_ptr = lt_dlsym(module,"mysql_field_tell");

			mysqlstub_field_count_ptr = lt_dlsym(module,"mysql_field_count");
			mysqlstub_affected_rows_ptr = lt_dlsym(module,"mysql_affected_rows");
			mysqlstub_insert_id_ptr = lt_dlsym(module,"mysql_insert_id");
			mysqlstub_errno_ptr = lt_dlsym(module,"mysql_errno");
			mysqlstub_error_ptr = lt_dlsym(module,"mysql_error");
			mysqlstub_sqlstate_ptr = lt_dlsym(module,"mysql_sqlstate");
			mysqlstub_warning_count_ptr = lt_dlsym(module,"mysql_warning_count");
			mysqlstub_info_ptr = lt_dlsym(module,"mysql_info");
			mysqlstub_thread_id_ptr = lt_dlsym(module,"mysql_thread_id");
			mysqlstub_character_set_name_ptr = lt_dlsym(module,"mysql_character_set_name");
			mysqlstub_set_character_set_ptr = lt_dlsym(module,"mysql_set_character_set");

			mysqlstub_init_ptr = lt_dlsym(module,"mysql_init");
			mysqlstub_ssl_set_ptr = lt_dlsym(module,"mysql_ssl_set");
			mysqlstub_get_ssl_cipher_ptr = lt_dlsym(module,"mysql_get_ssl_cipher");
			mysqlstub_change_user_ptr = lt_dlsym(module,"mysql_change_user");
			mysqlstub_real_connect_ptr = lt_dlsym(module,"mysql_real_connect");
			mysqlstub_select_db_ptr = lt_dlsym(module,"mysql_select_db");
			mysqlstub_query_ptr = lt_dlsym(module,"mysql_query");
			mysqlstub_send_query_ptr = lt_dlsym(module,"mysql_send_query");
			mysqlstub_real_query_ptr = lt_dlsym(module,"mysql_real_query");
			mysqlstub_store_result_ptr = lt_dlsym(module,"mysql_store_result");
			mysqlstub_use_result_ptr = lt_dlsym(module,"mysql_use_result");

			mysqlstub_get_character_set_info_ptr = lt_dlsym(module,"mysql_get_character_set_info");


			mysqlstub_shutdown_ptr = lt_dlsym(module,"mysql_shutdown");
			mysqlstub_dump_debug_info_ptr = lt_dlsym(module,"mysql_dump_debug_info");
			mysqlstub_refresh_ptr = lt_dlsym(module,"mysql_refresh");
			mysqlstub_kill_ptr = lt_dlsym(module,"mysql_kill");
			mysqlstub_set_server_option_ptr = lt_dlsym(module,"mysql_set_server_option");
			mysqlstub_ping_ptr = lt_dlsym(module,"mysql_ping");
			mysqlstub_stat_ptr = lt_dlsym(module,"mysql_stat");
			mysqlstub_get_server_info_ptr = lt_dlsym(module,"mysql_get_server_info");
			mysqlstub_get_client_info_ptr = lt_dlsym(module,"mysql_get_client_info");
			mysqlstub_get_client_version_ptr = lt_dlsym(module,"mysql_get_client_version");
			mysqlstub_get_host_info_ptr = lt_dlsym(module,"mysql_get_host_info");
			mysqlstub_get_server_version_ptr = lt_dlsym(module,"mysql_get_server_version");
			mysqlstub_get_proto_info_ptr = lt_dlsym(module,"mysql_get_proto_info");
			mysqlstub_list_dbs_ptr = lt_dlsym(module,"mysql_list_dbs");
			mysqlstub_list_tables_ptr = lt_dlsym(module,"mysql_list_tables");
			mysqlstub_list_processes_ptr = lt_dlsym(module,"mysql_list_processes");
			mysqlstub_options_ptr = lt_dlsym(module,"mysql_options");
			mysqlstub_free_result_ptr = lt_dlsym(module,"mysql_free_result");
			mysqlstub_data_seek_ptr = lt_dlsym(module,"mysql_data_seek");
			mysqlstub_row_seek_ptr = lt_dlsym(module,"mysql_row_seek");
			mysqlstub_field_seek_ptr = lt_dlsym(module,"mysql_field_seek");
			mysqlstub_fetch_row_ptr = lt_dlsym(module,"mysql_fetch_row");
			mysqlstub_fetch_lengths_ptr = lt_dlsym(module,"mysql_fetch_lengths");
			mysqlstub_fetch_field_ptr = lt_dlsym(module,"mysql_fetch_field");
			mysqlstub_list_fields_ptr = lt_dlsym(module,"mysql_list_fields");
			mysqlstub_escape_string_ptr = lt_dlsym(module,"mysql_escape_string");
			mysqlstub_hex_string_ptr = lt_dlsym(module,"mysql_hex_string");
			mysqlstub_real_escape_string_ptr = lt_dlsym(module,"mysql_real_escape_string");
			mysqlstub_debug_ptr = lt_dlsym(module,"mysql_debug");
			mysqlstub_thread_safe_ptr = lt_dlsym(module,"mysql_thread_safe");
			mysqlstub_embedded_ptr = lt_dlsym(module,"mysql_embedded");
			mysqlstub_read_query_result_ptr = lt_dlsym(module,"mysql_read_query_result");


			mysqlstub_stmt_init_ptr = lt_dlsym(module,"mysql_stmt_init");
			mysqlstub_stmt_prepare_ptr = lt_dlsym(module,"mysql_stmt_prepare");
			mysqlstub_stmt_execute_ptr = lt_dlsym(module,"mysql_stmt_execute");
			mysqlstub_stmt_fetch_ptr = lt_dlsym(module,"mysql_stmt_fetch");
			mysqlstub_stmt_fetch_column_ptr = lt_dlsym(module,"mysql_stmt_fetch_column");
			mysqlstub_stmt_store_result_ptr = lt_dlsym(module,"mysql_stmt_store_result");
			mysqlstub_stmt_param_count_ptr = lt_dlsym(module,"mysql_stmt_param_count");
			mysqlstub_stmt_attr_set_ptr = lt_dlsym(module,"mysql_stmt_attr_set");
			mysqlstub_stmt_attr_get_ptr = lt_dlsym(module,"mysql_stmt_attr_get");
			mysqlstub_stmt_bind_param_ptr = lt_dlsym(module,"mysql_stmt_bind_param");
			mysqlstub_stmt_bind_result_ptr = lt_dlsym(module,"mysql_stmt_bind_result");
			mysqlstub_stmt_close_ptr = lt_dlsym(module,"mysql_stmt_close");
			mysqlstub_stmt_reset_ptr = lt_dlsym(module,"mysql_stmt_reset");
			mysqlstub_stmt_free_result_ptr = lt_dlsym(module,"mysql_stmt_free_result");
			mysqlstub_stmt_send_long_data_ptr = lt_dlsym(module,"mysql_stmt_send_long_data");
			mysqlstub_stmt_result_metadata_ptr = lt_dlsym(module,"mysql_stmt_result_metadata");
			mysqlstub_stmt_param_metadata_ptr = lt_dlsym(module,"mysql_stmt_param_metadata");
			mysqlstub_stmt_errno_ptr = lt_dlsym(module,"mysql_stmt_errno");
			mysqlstub_stmt_error_ptr = lt_dlsym(module,"mysql_stmt_error");
			mysqlstub_stmt_sqlstate_ptr = lt_dlsym(module,"mysql_stmt_sqlstate");
			mysqlstub_stmt_row_seek_ptr = lt_dlsym(module,"mysql_stmt_row_seek");
			mysqlstub_stmt_row_tell_ptr = lt_dlsym(module,"mysql_stmt_row_tell");
			mysqlstub_stmt_data_seek_ptr = lt_dlsym(module,"mysql_stmt_data_seek");
			mysqlstub_stmt_num_rows_ptr = lt_dlsym(module,"mysql_stmt_num_rows");
			mysqlstub_stmt_affected_rows_ptr = lt_dlsym(module,"mysql_stmt_affected_rows");
			mysqlstub_stmt_insert_id_ptr = lt_dlsym(module,"mysql_stmt_insert_id");
			mysqlstub_stmt_field_count_ptr = lt_dlsym(module,"mysql_stmt_field_count");

			mysqlstub_commit_ptr = lt_dlsym(module,"mysql_commit");
			mysqlstub_rollback_ptr = lt_dlsym(module,"mysql_rollback");
			mysqlstub_autocommit_ptr = lt_dlsym(module,"mysql_autocommit");
			mysqlstub_more_results_ptr = lt_dlsym(module,"mysql_more_results");
			mysqlstub_next_result_ptr = lt_dlsym(module,"mysql_next_result");
			mysqlstub_stmt_next_result_ptr = lt_dlsym(module,"mysql_stmt_next_result");
			mysqlstub_close_ptr = lt_dlsym(module,"mysql_close");

		}


	} else {
		_mysqlstub_error(lt_dlerror());
	}


	return 0;
}

int mysqlstub_end_stub() {
	if (mysqlstub_inited != 0)
		return 0;

	if (ltdl==0) {
		if (module !=0) {
			if(lt_dlclose(module) != 0) {
				_mysqlstub_warning(lt_dlerror());
			}
			module = 0;
		}
		lt_dlexit();
		ltdl = 0;
		mysqlstub_inited = 0;

	}

	return 0;
}

int  mysqlstub_server_init(int argc, char **argv, char **groups){
	if(mysqlstub_server_init_ptr != NULL)
		return (mysqlstub_server_init_ptr)(argc,argv,groups);
	abort();
}


void  mysqlstub_server_end(void){
	if(mysqlstub_server_end_ptr != NULL)
		return (mysqlstub_server_end_ptr)();
	abort();
}


MYSQL_PARAMETERS * mysqlstub_get_parameters(void){
	if(mysqlstub_get_parameters_ptr != NULL)
		return (mysqlstub_get_parameters_ptr)();
	abort();
}



my_bool  mysqlstub_thread_init(void){
	if(mysqlstub_thread_init_ptr != NULL)
		return (mysqlstub_thread_init_ptr)();
	abort();
}


void  mysqlstub_thread_end(void){
	if(mysqlstub_thread_end_ptr != NULL)
		return (mysqlstub_thread_end_ptr)();
	abort();
}




my_ulonglong  mysqlstub_num_rows(MYSQL_RES *res){
	if(mysqlstub_num_rows_ptr != NULL)
		return (mysqlstub_num_rows_ptr)(res);
	abort();
}


unsigned int  mysqlstub_num_fields(MYSQL_RES *res){
	if(mysqlstub_num_fields_ptr != NULL)
		return (mysqlstub_num_fields_ptr)(res);
	abort();
}


my_bool  mysqlstub_eof(MYSQL_RES *res){
	if(mysqlstub_eof_ptr != NULL)
		return (mysqlstub_eof_ptr)(res);
	abort();
}


MYSQL_FIELD * mysqlstub_fetch_field_direct(MYSQL_RES *res,
		unsigned int fieldnr){
	if(mysqlstub_fetch_field_ptr != NULL)
		return (mysqlstub_fetch_field_direct_ptr)(res,fieldnr);
	abort();
}


MYSQL_FIELD *  mysqlstub_fetch_fields(MYSQL_RES *res){
	if(mysqlstub_fetch_fields_ptr != NULL)
		return (mysqlstub_fetch_fields_ptr)(res);
	abort();
}


MYSQL_ROW_OFFSET  mysqlstub_row_tell(MYSQL_RES *res){
	if(mysqlstub_row_tell_ptr != NULL)
		return (mysqlstub_row_tell_ptr)(res);
	abort();
}


MYSQL_FIELD_OFFSET  mysqlstub_field_tell(MYSQL_RES *res){
	if(mysqlstub_field_tell_ptr != NULL)
		return (mysqlstub_field_tell_ptr)(res);
	abort();
}



unsigned int  mysqlstub_field_count(MYSQL *mysql){
	if(mysqlstub_field_count_ptr != NULL)
		return (mysqlstub_field_count_ptr)(mysql);
	abort();
}


my_ulonglong  mysqlstub_affected_rows(MYSQL *mysql){
	if(mysqlstub_affected_rows_ptr != NULL)
		return (mysqlstub_affected_rows_ptr)(mysql);
	abort();
}


my_ulonglong  mysqlstub_insert_id(MYSQL *mysql){
	if(mysqlstub_insert_id_ptr != NULL)
		return (mysqlstub_insert_id_ptr)(mysql);
	abort();

}


unsigned int  mysqlstub_errno(MYSQL *mysql){
	if(mysqlstub_errno_ptr != NULL)
		return (mysqlstub_errno_ptr)(mysql);
	abort();

}


const char *  mysqlstub_error(MYSQL *mysql){
	if(mysqlstub_error_ptr != NULL)
		return (mysqlstub_error_ptr)(mysql);
	abort();

}


const char * mysqlstub_sqlstate(MYSQL *mysql){
	if(mysqlstub_sqlstate_ptr != NULL)
		return (mysqlstub_sqlstate_ptr)(mysql);
	abort();

}


unsigned int  mysqlstub_warning_count(MYSQL *mysql){
	if(mysqlstub_warning_count_ptr != NULL)
		return (mysqlstub_warning_count_ptr)(mysql);
	abort();

}


const char *  mysqlstub_info(MYSQL *mysql){
	if(mysqlstub_info_ptr != NULL)
		return (mysqlstub_info_ptr)(mysql);
	abort();

}


unsigned long  mysqlstub_thread_id(MYSQL *mysql){
	if(mysqlstub_thread_id_ptr != NULL)
		return (mysqlstub_thread_id_ptr)(mysql);
	abort();

}


const char *  mysqlstub_character_set_name(MYSQL *mysql){
	if(mysqlstub_character_set_name_ptr != NULL)
		return (mysqlstub_character_set_name_ptr)(mysql);
	abort();

}


int           mysqlstub_set_character_set(MYSQL *mysql, const char *csname){
	if(mysqlstub_set_character_set_ptr != NULL)
		return (mysqlstub_set_character_set_ptr)(mysql,csname);
	abort();

}



MYSQL *		 mysqlstub_init(MYSQL *mysql){
	if(mysqlstub_init_ptr != NULL)
		return (mysqlstub_init_ptr)(mysql);
	abort();

}


my_bool		 mysqlstub_ssl_set(MYSQL *mysql, const char *key,
		const char *cert, const char *ca,
		const char *capath, const char *cipher){
	if(mysqlstub_ssl_set_ptr != NULL)
		return (mysqlstub_ssl_set_ptr)(mysql, key,cert, ca, capath, cipher);
	abort();

}


const char *     mysqlstub_get_ssl_cipher(MYSQL *mysql){
	if(mysqlstub_get_ssl_cipher_ptr != NULL)
		return (mysqlstub_get_ssl_cipher_ptr)(mysql);
	abort();

}


my_bool		 mysqlstub_change_user(MYSQL *mysql, const char *user,
		const char *passwd, const char *db){
	if(mysqlstub_change_user_ptr != NULL)
		return (mysqlstub_change_user_ptr)(mysql,user,passwd,db);
	abort();

}


MYSQL *		 mysqlstub_real_connect(MYSQL *mysql, const char *host,
		const char *user,
		const char *passwd,
		const char *db,
		unsigned int port,
		const char *unix_socket,
		unsigned long clientflag){
	if(mysqlstub_real_connect_ptr != NULL)
		return (mysqlstub_real_connect_ptr)(mysql,host,user,passwd,db,port,unix_socket,clientflag);
	abort();

}


int		 mysqlstub_select_db(MYSQL *mysql, const char *db){
	if(mysqlstub_select_db_ptr!= NULL)
		return (mysqlstub_select_db_ptr)(mysql,db);
	abort();

}


int		 mysqlstub_query(MYSQL *mysql, const char *q){
	if(mysqlstub_query_ptr != NULL)
		return (mysqlstub_query_ptr)(mysql,q);
	abort();

}


int		 mysqlstub_send_query(MYSQL *mysql, const char *q,
		unsigned long length){
	if(mysqlstub_send_query_ptr != NULL)
		return (mysqlstub_send_query)(mysql,q,length);
	abort();

}


int		 mysqlstub_real_query(MYSQL *mysql, const char *q,
		unsigned long length){
	if(mysqlstub_real_query_ptr != NULL)
		return (mysqlstub_real_query)(mysql,q,length);
	abort();

}


MYSQL_RES *      mysqlstub_store_result(MYSQL *mysql){
	if(mysqlstub_store_result_ptr != NULL)
		return (mysqlstub_store_result_ptr)(mysql);
	abort();

}


MYSQL_RES *      mysqlstub_use_result(MYSQL *mysql){
	if(mysqlstub_use_result_ptr != NULL)
		return (mysqlstub_use_result_ptr)(mysql);
	abort();

}



void         mysqlstub_get_character_set_info(MYSQL *mysql,
		MY_CHARSET_INFO *charset){
	if(mysqlstub_get_character_set_info_ptr!= NULL)
		return (mysqlstub_get_character_set_info_ptr)(mysql,charset);
	abort();

}






int		 mysqlstub_shutdown(MYSQL *mysql,
		enum mysql_enum_shutdown_level
		shutdown_level){
	if(mysqlstub_shutdown_ptr!= NULL)
		return (mysqlstub_shutdown_ptr)(mysql,shutdown_level);
	abort();

}


int		 mysqlstub_dump_debug_info(MYSQL *mysql){
	if(mysqlstub_dump_debug_info_ptr != NULL)
		return (mysqlstub_dump_debug_info)(mysql);
	abort();

}


int		 mysqlstub_refresh(MYSQL *mysql,
		unsigned int refresh_options){
	if(mysqlstub_refresh_ptr != NULL)
		return (mysqlstub_refresh_ptr)(mysql,refresh_options);
	abort();

}


int		 mysqlstub_kill(MYSQL *mysql,unsigned long pid){
	if(mysqlstub_kill_ptr != NULL)
		return (mysqlstub_kill_ptr)(mysql,pid);
	abort();

}


int		 mysqlstub_set_server_option(MYSQL *mysql,
		enum enum_mysql_set_option
		option){
	if(mysqlstub_set_server_option_ptr != NULL)
		return (mysqlstub_set_server_option_ptr)(mysql,option);
	abort();

}


int		 mysqlstub_ping(MYSQL *mysql){
	if(mysqlstub_ping_ptr != NULL)
		return (mysqlstub_ping_ptr)(mysql);
	abort();

}


const char *	 mysqlstub_stat(MYSQL *mysql){
	if(mysqlstub_stat_ptr!= NULL)
		return (mysqlstub_stat_ptr)(mysql);
	abort();

}


const char *	 mysqlstub_get_server_info(MYSQL *mysql){
	if(mysqlstub_get_server_info_ptr!= NULL)
		return (mysqlstub_get_server_info_ptr)(mysql);
	abort();

}


const char *	 mysqlstub_get_client_info(void){
	if(mysqlstub_get_client_info_ptr != NULL)
		return (mysqlstub_get_client_info_ptr)();
	abort();

}


unsigned long	 mysqlstub_get_client_version(void){
	if(mysqlstub_get_client_version_ptr != NULL)
		return (mysqlstub_get_client_version_ptr)();
	abort();

}


const char *	 mysqlstub_get_host_info(MYSQL *mysql){
	if(mysqlstub_get_host_info_ptr!= NULL)
		return (mysqlstub_get_host_info_ptr)(mysql);
	abort();

}


unsigned long	 mysqlstub_get_server_version(MYSQL *mysql){
	if(mysqlstub_get_server_version_ptr!= NULL)
		return (mysqlstub_get_server_version_ptr)(mysql);
	abort();

}


unsigned int	 mysqlstub_get_proto_info(MYSQL *mysql){
	if(mysqlstub_get_proto_info_ptr!= NULL)
		return (mysqlstub_get_proto_info_ptr)(mysql);
	abort();

}


MYSQL_RES *	 mysqlstub_list_dbs(MYSQL *mysql,const char *wild){
	if(mysqlstub_list_dbs_ptr!= NULL)
		return (mysqlstub_list_dbs_ptr)(mysql,wild);
	abort();

}


MYSQL_RES *	 mysqlstub_list_tables(MYSQL *mysql,const char *wild){
	if(mysqlstub_list_tables_ptr!= NULL)
		return (mysqlstub_list_tables_ptr)(mysql,wild);
	abort();

}


MYSQL_RES *	 mysqlstub_list_processes(MYSQL *mysql){
	if(mysqlstub_list_processes_ptr != NULL)
		return (mysqlstub_list_processes_ptr)(mysql);
	abort();

}


int		 mysqlstub_options(MYSQL *mysql,enum mysql_option option,
		const void *arg){
	if(mysqlstub_options_ptr != NULL)
		return (mysqlstub_options_ptr)(mysql,option,arg);
	abort();

}


void		 mysqlstub_free_result(MYSQL_RES *result){
	if(mysqlstub_free_result_ptr != NULL)
		return (mysqlstub_free_result_ptr)(result);
	abort();

}


void		 mysqlstub_data_seek(MYSQL_RES *result,
		my_ulonglong offset){
	if(mysqlstub_data_seek_ptr!= NULL)
		return (mysqlstub_data_seek_ptr)(result,offset);
	abort();
}


MYSQL_ROW_OFFSET  mysqlstub_row_seek(MYSQL_RES *result,
		MYSQL_ROW_OFFSET offset){
	if(mysqlstub_row_seek_ptr != NULL)
		return (mysqlstub_row_seek_ptr)(result,offset);
	abort();
}


MYSQL_FIELD_OFFSET  mysqlstub_field_seek(MYSQL_RES *result,
		MYSQL_FIELD_OFFSET offset){
	if(mysqlstub_field_seek_ptr!= NULL)
		return (mysqlstub_field_seek_ptr)(result,offset);
	abort();
}


MYSQL_ROW	 mysqlstub_fetch_row(MYSQL_RES *result){
	if(mysqlstub_fetch_row != NULL)
		return (mysqlstub_fetch_row_ptr)(result);
	abort();
}


unsigned long *  mysqlstub_fetch_lengths(MYSQL_RES *result){
	if(mysqlstub_fetch_lengths_ptr != NULL)
		return (mysqlstub_fetch_lengths_ptr)(result);
	abort();
}


MYSQL_FIELD *	 mysqlstub_fetch_field(MYSQL_RES *result){
	if(mysqlstub_fetch_field_ptr != NULL)
		return (mysqlstub_fetch_field_ptr)(result);
	abort();
}


MYSQL_RES *      mysqlstub_list_fields(MYSQL *mysql, const char *table,
		const char *wild){
	if(mysqlstub_fetch_fields_ptr!= NULL)
		return (mysqlstub_list_fields_ptr)(mysql,table,wild);
	abort();
}


unsigned long	 mysqlstub_escape_string(char *to,const char *from,
		unsigned long from_length){
	if(mysqlstub_escape_string_ptr != NULL)
		return (mysqlstub_escape_string_ptr)(to,from,from_length);
	abort();
}


unsigned long	 mysqlstub_hex_string(char *to,const char *from,
		unsigned long from_length){
	if(mysqlstub_hex_string_ptr != NULL)
		return (mysqlstub_hex_string_ptr)(to,from,from_length);
	abort();
}


unsigned long  mysqlstub_real_escape_string(MYSQL *mysql,
		char *to,const char *from,
		unsigned long length){
	if(mysqlstub_real_escape_string_ptr != NULL)
		return (mysqlstub_real_escape_string_ptr)(mysql,to,from,length);
	abort();
}


void		 mysqlstub_debug(const char *debug){
	if(mysqlstub_debug_ptr!= NULL)
		return (mysqlstub_debug_ptr)(debug);
	abort();
}


unsigned int	 mysqlstub_thread_safe(void){
	if(mysqlstub_thread_safe_ptr!= NULL)
		return (mysqlstub_thread_safe_ptr)();
	abort();
}


my_bool		 mysqlstub_embedded(void){
	if(mysqlstub_embedded_ptr!= NULL)
		return (mysqlstub_embedded_ptr)();
	abort();
}


my_bool          mysqlstub_read_query_result(MYSQL *mysql){
	if(mysqlstub_read_query_result_ptr!= NULL)
		return (mysqlstub_read_query_result_ptr)(mysql);
	abort();
}




MYSQL_STMT *  mysqlstub_stmt_init(MYSQL *mysql){
	if(mysqlstub_stmt_init_ptr!= NULL)
		return (mysqlstub_stmt_init_ptr)(mysql);
	abort();

}


int  mysqlstub_stmt_prepare(MYSQL_STMT *stmt, const char *query,
		unsigned long length){
	if(mysqlstub_stmt_prepare_ptr!= NULL)
		return (mysqlstub_stmt_prepare_ptr)(stmt,query,length);
	abort();

}


int  mysqlstub_stmt_execute(MYSQL_STMT *stmt){
	if(mysqlstub_stmt_execute_ptr!= NULL)
		return (mysqlstub_stmt_execute_ptr)(stmt);
	abort();

}


int  mysqlstub_stmt_fetch(MYSQL_STMT *stmt){
	if(mysqlstub_stmt_fetch_ptr!= NULL)
		return (mysqlstub_stmt_fetch_ptr)(stmt);
	abort();
}


int  mysqlstub_stmt_fetch_column(MYSQL_STMT *stmt, MYSQL_BIND *bind_arg,
		unsigned int column,
		unsigned long offset){
	if(mysqlstub_stmt_fetch_column_ptr!= NULL)
		return (mysqlstub_stmt_fetch_column_ptr)(stmt,bind_arg,column,offset);
	abort();
}


int  mysqlstub_stmt_store_result(MYSQL_STMT *stmt){
	if(mysqlstub_stmt_store_result_ptr!= NULL)
		return (mysqlstub_stmt_store_result_ptr)(stmt);
	abort();
}


unsigned long  mysqlstub_stmt_param_count(MYSQL_STMT * stmt){
	if(mysqlstub_stmt_param_count_ptr!= NULL)
		return (mysqlstub_stmt_param_count_ptr)(stmt);
	abort();
}


my_bool  mysqlstub_stmt_attr_set(MYSQL_STMT *stmt,
		enum enum_stmt_attr_type attr_type,
		const void *attr){
	if(mysqlstub_stmt_attr_set_ptr!= NULL)
		return (mysqlstub_stmt_attr_set_ptr)(stmt,attr_type,attr);
	abort();
}


my_bool  mysqlstub_stmt_attr_get(MYSQL_STMT *stmt,
		enum enum_stmt_attr_type attr_type,
		void *attr){
	if(mysqlstub_stmt_attr_get_ptr!= NULL)
		return (mysqlstub_stmt_attr_get_ptr)(stmt,attr_type,attr);
	abort();
}


my_bool  mysqlstub_stmt_bind_param(MYSQL_STMT * stmt, MYSQL_BIND * bnd){
	if(mysqlstub_stmt_bind_param_ptr!= NULL)
		return (mysqlstub_stmt_bind_param_ptr)(stmt,bnd);
	abort();
}


my_bool  mysqlstub_stmt_bind_result(MYSQL_STMT * stmt, MYSQL_BIND * bnd){
	if(mysqlstub_stmt_bind_result_ptr!= NULL)
		return (mysqlstub_stmt_bind_result_ptr)(stmt,bnd);
	abort();
}


my_bool  mysqlstub_stmt_close(MYSQL_STMT * stmt){
	if(mysqlstub_stmt_close_ptr!= NULL)
		return (mysqlstub_stmt_close_ptr)(stmt);
	abort();
}


my_bool  mysqlstub_stmt_reset(MYSQL_STMT * stmt){
	if(mysqlstub_stmt_reset_ptr!= NULL)
		return (mysqlstub_stmt_reset_ptr)(stmt);
	abort();
}


my_bool  mysqlstub_stmt_free_result(MYSQL_STMT *stmt){
	if(mysqlstub_stmt_free_result_ptr!= NULL)
		return (mysqlstub_stmt_free_result_ptr)(stmt);
	abort();
}


my_bool  mysqlstub_stmt_send_long_data(MYSQL_STMT *stmt,
		unsigned int param_number,
		const char *data,
		unsigned long length){
	if(mysqlstub_stmt_send_long_data_ptr!= NULL)
		return (mysqlstub_stmt_send_long_data_ptr)(stmt,param_number,data,length);
	abort();
}



MYSQL_RES * mysqlstub_stmt_result_metadata(MYSQL_STMT *stmt){
	if(mysqlstub_stmt_result_metadata_ptr!= NULL)
		return (mysqlstub_stmt_result_metadata_ptr)(stmt);
	abort();

}

MYSQL_RES * mysqlstub_stmt_param_metadata(MYSQL_STMT *stmt){
	if(mysqlstub_stmt_param_metadata_ptr!= NULL)
		return (mysqlstub_stmt_param_metadata_ptr)(stmt);
	abort();

}


unsigned int  mysqlstub_stmt_errno(MYSQL_STMT * stmt){
	if(mysqlstub_stmt_errno_ptr!= NULL)
		return (mysqlstub_stmt_errno_ptr)(stmt);
	abort();

}


const char * mysqlstub_stmt_error(MYSQL_STMT * stmt){
	if(mysqlstub_stmt_error_ptr!= NULL)
		return (mysqlstub_stmt_error_ptr)(stmt);
	abort();

}


const char * mysqlstub_stmt_sqlstate(MYSQL_STMT * stmt){
	if(mysqlstub_stmt_sqlstate_ptr!= NULL)
		return (mysqlstub_stmt_sqlstate_ptr)(stmt);
	abort();

}


MYSQL_ROW_OFFSET  mysqlstub_stmt_row_seek(MYSQL_STMT *stmt,
		MYSQL_ROW_OFFSET offset){
	if(mysqlstub_stmt_row_seek_ptr!= NULL)
		return (mysqlstub_stmt_row_seek_ptr)(stmt,offset);
	abort();

}


MYSQL_ROW_OFFSET  mysqlstub_stmt_row_tell(MYSQL_STMT *stmt){
	if(mysqlstub_stmt_row_tell_ptr!= NULL)
		return (mysqlstub_stmt_row_tell_ptr)(stmt);
	abort();

}


void  mysqlstub_stmt_data_seek(MYSQL_STMT *stmt, my_ulonglong offset){
	if(mysqlstub_stmt_data_seek_ptr!= NULL)
		return (mysqlstub_stmt_data_seek_ptr)(stmt,offset);
	abort();

}


my_ulonglong  mysqlstub_stmt_num_rows(MYSQL_STMT *stmt){
	if(mysqlstub_stmt_num_rows_ptr!= NULL)
		return (mysqlstub_stmt_num_rows_ptr)(stmt);
	abort();

}


my_ulonglong  mysqlstub_stmt_affected_rows(MYSQL_STMT *stmt){
	if(mysqlstub_stmt_affected_rows_ptr!= NULL)
		return (mysqlstub_stmt_affected_rows_ptr)(stmt);
	abort();

}


my_ulonglong  mysqlstub_stmt_insert_id(MYSQL_STMT *stmt){
	if(mysqlstub_stmt_insert_id_ptr!= NULL)
		return (mysqlstub_stmt_insert_id_ptr)(stmt);
	abort();

}


unsigned int  mysqlstub_stmt_field_count(MYSQL_STMT *stmt){
	if(mysqlstub_stmt_field_count_ptr!= NULL)
		return (mysqlstub_stmt_field_count_ptr)(stmt);
	abort();

}



my_bool  mysqlstub_commit(MYSQL * mysql){
	if(mysqlstub_commit_ptr!= NULL)
		return (mysqlstub_commit_ptr)(mysql);
	abort();

}


my_bool  mysqlstub_rollback(MYSQL * mysql){
	if(mysqlstub_rollback_ptr!= NULL)
		return (mysqlstub_rollback_ptr)(mysql);
	abort();
}


my_bool  mysqlstub_autocommit(MYSQL * mysql, my_bool auto_mode){
	if(mysqlstub_autocommit_ptr!= NULL)
		return (mysqlstub_autocommit_ptr)(mysql,auto_mode);
	abort();
}


my_bool  mysqlstub_more_results(MYSQL *mysql){
	if(mysqlstub_more_results_ptr!= NULL)
		return (mysqlstub_more_results_ptr)(mysql);
	abort();
}


int  mysqlstub_next_result(MYSQL *mysql){
	if(mysqlstub_next_result_ptr!= NULL)
		return (mysqlstub_next_result_ptr)(mysql);
	abort();
}


int  mysqlstub_stmt_next_result(MYSQL_STMT *stmt){
	if(mysqlstub_stmt_next_result_ptr!= NULL)
		return (mysqlstub_stmt_next_result_ptr)(stmt);
	abort();
}


void  mysqlstub_close(MYSQL *sock){
	if(mysqlstub_close_ptr!= NULL)
		return (mysqlstub_close_ptr)(sock);
	abort();
}



