/*
 * mysqlstub_private.h
 *
 *  Created on: 13-mei-2014
 *      Author: vincent
 */


#ifndef MYSQLSTUB_PRIVATE_H_
#define MYSQLSTUB_PRIVATE_H_

#include "mysqlstub.h"


typedef int  (*mysqlstub_server_init_t)(int argc, char **argv, char **groups);
typedef void  (*mysqlstub_server_end_t)(void);


typedef MYSQL_PARAMETERS * (*mysqlstub_get_parameters_t)(void);

typedef my_bool  (*mysqlstub_thread_init_t)(void);
typedef void  (*mysqlstub_thread_end_t)(void);


typedef my_ulonglong  (*mysqlstub_num_rows_t)(MYSQL_RES *res);
typedef unsigned int  (*mysqlstub_num_fields_t)(MYSQL_RES *res);
typedef my_bool  (*mysqlstub_eof_t)(MYSQL_RES *res);
typedef MYSQL_FIELD * (*mysqlstub_fetch_field_direct_t)(MYSQL_RES *res,
		unsigned int fieldnr);
typedef MYSQL_FIELD *  (*mysqlstub_fetch_fields_t)(MYSQL_RES *res);
typedef MYSQL_ROW_OFFSET  (*mysqlstub_row_tell_t)(MYSQL_RES *res);
typedef MYSQL_FIELD_OFFSET  (*mysqlstub_field_tell_t)(MYSQL_RES *res);

typedef unsigned int  (*mysqlstub_field_count_t)(MYSQL *mysql);
typedef my_ulonglong  (*mysqlstub_affected_rows_t)(MYSQL *mysql);
typedef my_ulonglong  (*mysqlstub_insert_id_t)(MYSQL *mysql);
typedef unsigned int  (*mysqlstub_errno_t)(MYSQL *mysql);
typedef const char *  (*mysqlstub_error_t)(MYSQL *mysql);
typedef const char * (*mysqlstub_sqlstate_t)(MYSQL *mysql);
typedef unsigned int  (*mysqlstub_warning_count_t)(MYSQL *mysql);
typedef const char *  (*mysqlstub_info_t)(MYSQL *mysql);
typedef unsigned long  (*mysqlstub_thread_id_t)(MYSQL *mysql);
typedef const char *  (*mysqlstub_character_set_name_t)(MYSQL *mysql);
typedef int           (*mysqlstub_set_character_set_t)(MYSQL *mysql, const char *csname);

typedef MYSQL *		 (*mysqlstub_init_t)(MYSQL *mysql);
typedef my_bool		 (*mysqlstub_ssl_set_t)(MYSQL *mysql, const char *key,
		const char *cert, const char *ca,
		const char *capath, const char *cipher);
typedef const char *     (*mysqlstub_get_ssl_cipher_t)(MYSQL *mysql);
typedef my_bool		 (*mysqlstub_change_user_t)(MYSQL *mysql, const char *user,
		const char *passwd, const char *db);
typedef MYSQL *		 (*mysqlstub_real_connect_t)(MYSQL *mysql, const char *host,
		const char *user,
		const char *passwd,
		const char *db,
		unsigned int port,
		const char *unix_socket,
		unsigned long clientflag);
typedef int		 (*mysqlstub_select_db_t)(MYSQL *mysql, const char *db);
typedef int		 (*mysqlstub_query_t)(MYSQL *mysql, const char *q);
typedef int		 (*mysqlstub_send_query_t)(MYSQL *mysql, const char *q,
		unsigned long length);
typedef int		 (*mysqlstub_real_query_t)(MYSQL *mysql, const char *q,
		unsigned long length);
typedef MYSQL_RES *      (*mysqlstub_store_result_t)(MYSQL *mysql);
typedef MYSQL_RES *      (*mysqlstub_use_result_t)(MYSQL *mysql);

typedef void         (*mysqlstub_get_character_set_info_t)(MYSQL *mysql,
		MY_CHARSET_INFO *charset);



typedef int		 (*mysqlstub_shutdown_t)(MYSQL *mysql,
		enum mysql_enum_shutdown_level
		shutdown_level);
typedef int		 (*mysqlstub_dump_debug_info_t)(MYSQL *mysql);
typedef int		 (*mysqlstub_refresh_t)(MYSQL *mysql,
		unsigned int refresh_options);
typedef int		 (*mysqlstub_kill_t)(MYSQL *mysql,unsigned long pid);
typedef int		 (*mysqlstub_set_server_option_t)(MYSQL *mysql,
		enum enum_mysql_set_option
		option);
typedef int		 (*mysqlstub_ping_t)(MYSQL *mysql);
typedef const char *	 (*mysqlstub_stat_t)(MYSQL *mysql);
typedef const char *	 (*mysqlstub_get_server_info_t)(MYSQL *mysql);
typedef const char *	 (*mysqlstub_get_client_info_t)(void);
typedef unsigned long	 (*mysqlstub_get_client_version_t)(void);
typedef const char *	 (*mysqlstub_get_host_info_t)(MYSQL *mysql);
typedef unsigned long	 (*mysqlstub_get_server_version_t)(MYSQL *mysql);
typedef unsigned int	 (*mysqlstub_get_proto_info_t)(MYSQL *mysql);
typedef MYSQL_RES *	 (*mysqlstub_list_dbs_t)(MYSQL *mysql,const char *wild);
typedef MYSQL_RES *	 (*mysqlstub_list_tables_t)(MYSQL *mysql,const char *wild);
typedef MYSQL_RES *	 (*mysqlstub_list_processes_t)(MYSQL *mysql);
typedef int		 (*mysqlstub_options_t)(MYSQL *mysql,enum mysql_option option,
		const void *arg);
typedef void		 (*mysqlstub_free_result_t)(MYSQL_RES *result);
typedef void		 (*mysqlstub_data_seek_t)(MYSQL_RES *result,
		my_ulonglong offset);
typedef MYSQL_ROW_OFFSET  (*mysqlstub_row_seek_t)(MYSQL_RES *result,
		MYSQL_ROW_OFFSET offset);
typedef MYSQL_FIELD_OFFSET  (*mysqlstub_field_seek_t)(MYSQL_RES *result,
		MYSQL_FIELD_OFFSET offset);
typedef MYSQL_ROW	 (*mysqlstub_fetch_row_t)(MYSQL_RES *result);
typedef unsigned long *  (*mysqlstub_fetch_lengths_t)(MYSQL_RES *result);
typedef MYSQL_FIELD *	 (*mysqlstub_fetch_field_t)(MYSQL_RES *result);
typedef MYSQL_RES *      (*mysqlstub_list_fields_t)(MYSQL *mysql, const char *table,
		const char *wild);
typedef unsigned long	 (*mysqlstub_escape_string_t)(char *to,const char *from,
		unsigned long from_length);
typedef unsigned long	 (*mysqlstub_hex_string_t)(char *to,const char *from,
		unsigned long from_length);
typedef unsigned long  (*mysqlstub_real_escape_string_t)(MYSQL *mysql,
		char *to,const char *from,
		unsigned long length);
typedef void		 (*mysqlstub_debug_t)(const char *debug);
typedef unsigned int	 (*mysqlstub_thread_safe_t)(void);
typedef my_bool		 (*mysqlstub_embedded_t)(void);
typedef my_bool         (* mysqlstub_read_query_result_t)(MYSQL *mysql);


typedef MYSQL_STMT *  (*mysqlstub_stmt_init_t)(MYSQL *mysql);
typedef int  (*mysqlstub_stmt_prepare_t)(MYSQL_STMT *stmt, const char *query,
		unsigned long length);
typedef int  (*mysqlstub_stmt_execute_t)(MYSQL_STMT *stmt);
typedef int  (*mysqlstub_stmt_fetch_t)(MYSQL_STMT *stmt);
typedef int  (*mysqlstub_stmt_fetch_column_t)(MYSQL_STMT *stmt, MYSQL_BIND *bind_arg,
		unsigned int column,
		unsigned long offset);
typedef int  (*mysqlstub_stmt_store_result_t)(MYSQL_STMT *stmt);
typedef unsigned long  (*mysqlstub_stmt_param_count_t)(MYSQL_STMT * stmt);
typedef my_bool  (*mysqlstub_stmt_attr_set_t)(MYSQL_STMT *stmt,
		enum enum_stmt_attr_type attr_type,
		const void *attr);
typedef my_bool  (*mysqlstub_stmt_attr_get_t)(MYSQL_STMT *stmt,
		enum enum_stmt_attr_type attr_type,
		void *attr);
typedef my_bool  (*mysqlstub_stmt_bind_param_t)(MYSQL_STMT * stmt, MYSQL_BIND * bnd);
typedef my_bool  (*mysqlstub_stmt_bind_result_t)(MYSQL_STMT * stmt, MYSQL_BIND * bnd);
typedef my_bool  (*mysqlstub_stmt_close_t)(MYSQL_STMT * stmt);
typedef my_bool  (*mysqlstub_stmt_reset_t)(MYSQL_STMT * stmt);
typedef my_bool  (*mysqlstub_stmt_free_result_t)(MYSQL_STMT *stmt);
typedef my_bool  (*mysqlstub_stmt_send_long_data_t)(MYSQL_STMT *stmt,
		unsigned int param_number,
		const char *data,
		unsigned long length);
typedef MYSQL_RES * (*mysqlstub_stmt_result_metadata_t)(MYSQL_STMT *stmt);
typedef MYSQL_RES * (*mysqlstub_stmt_param_metadata_t)(MYSQL_STMT *stmt);
typedef unsigned int  (*mysqlstub_stmt_errno_t)(MYSQL_STMT * stmt);
typedef const char * (*mysqlstub_stmt_error_t)(MYSQL_STMT * stmt);
typedef const char * (*mysqlstub_stmt_sqlstate_t)(MYSQL_STMT * stmt);
typedef MYSQL_ROW_OFFSET  (*mysqlstub_stmt_row_seek_t)(MYSQL_STMT *stmt,
		MYSQL_ROW_OFFSET offset);
typedef MYSQL_ROW_OFFSET  (*mysqlstub_stmt_row_tell_t)(MYSQL_STMT *stmt);
typedef void  (*mysqlstub_stmt_data_seek_t)(MYSQL_STMT *stmt, my_ulonglong offset);
typedef my_ulonglong  (*mysqlstub_stmt_num_rows_t)(MYSQL_STMT *stmt);
typedef my_ulonglong  (*mysqlstub_stmt_affected_rows_t)(MYSQL_STMT *stmt);
typedef my_ulonglong  (*mysqlstub_stmt_insert_id_t)(MYSQL_STMT *stmt);
typedef unsigned int  (*mysqlstub_stmt_field_count_t)(MYSQL_STMT *stmt);

typedef my_bool  (*mysqlstub_commit_t)(MYSQL * mysql);
typedef my_bool  (*mysqlstub_rollback_t)(MYSQL * mysql);
typedef my_bool  (*mysqlstub_autocommit_t)(MYSQL * mysql, my_bool auto_mode);
typedef my_bool  (*mysqlstub_more_results_t)(MYSQL *mysql);
typedef int  (*mysqlstub_next_result_t)(MYSQL *mysql);
typedef int  (*mysqlstub_stmt_next_result_t)(MYSQL_STMT *stmt);
typedef void  (*mysqlstub_close_t)(MYSQL *sock);



#endif /* MYSQLSTUB_PRIVATE_H_ */
