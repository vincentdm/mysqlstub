#ifndef libmysqlstub_h
#define libmysqlstub_h

#include <mysql/mysql.h>


int mysqlstub_init_stub();
int mysqlstub_end_stub();


int  mysqlstub_server_init(int argc, char **argv, char **groups);
void  mysqlstub_server_end(void);

#define mysqlstub_library_init mysqlstub_server_init
#define mysqlstub_library_end mysqlstub_server_end

MYSQL_PARAMETERS * mysqlstub_get_parameters(void);

my_bool  mysqlstub_thread_init(void);
void  mysqlstub_thread_end(void);


my_ulonglong  mysqlstub_num_rows(MYSQL_RES *res);
unsigned int  mysqlstub_num_fields(MYSQL_RES *res);
my_bool  mysqlstub_eof(MYSQL_RES *res);
MYSQL_FIELD * mysqlstub_fetch_field_direct(MYSQL_RES *res,
					      unsigned int fieldnr);
MYSQL_FIELD *  mysqlstub_fetch_fields(MYSQL_RES *res);
MYSQL_ROW_OFFSET  mysqlstub_row_tell(MYSQL_RES *res);
MYSQL_FIELD_OFFSET  mysqlstub_field_tell(MYSQL_RES *res);

unsigned int  mysqlstub_field_count(MYSQL *mysql);
my_ulonglong  mysqlstub_affected_rows(MYSQL *mysql);
my_ulonglong  mysqlstub_insert_id(MYSQL *mysql);
unsigned int  mysqlstub_errno(MYSQL *mysql);
const char *  mysqlstub_error(MYSQL *mysql);
const char * mysqlstub_sqlstate(MYSQL *mysql);
unsigned int  mysqlstub_warning_count(MYSQL *mysql);
const char *  mysqlstub_info(MYSQL *mysql);
unsigned long  mysqlstub_thread_id(MYSQL *mysql);
const char *  mysqlstub_character_set_name(MYSQL *mysql);
int           mysqlstub_set_character_set(MYSQL *mysql, const char *csname);

MYSQL *		 mysqlstub_init(MYSQL *mysql);
my_bool		 mysqlstub_ssl_set(MYSQL *mysql, const char *key,
				      const char *cert, const char *ca,
				      const char *capath, const char *cipher);
const char *     mysqlstub_get_ssl_cipher(MYSQL *mysql);
my_bool		 mysqlstub_change_user(MYSQL *mysql, const char *user,
					  const char *passwd, const char *db);
MYSQL *		 mysqlstub_real_connect(MYSQL *mysql, const char *host,
					   const char *user,
					   const char *passwd,
					   const char *db,
					   unsigned int port,
					   const char *unix_socket,
					   unsigned long clientflag);
int		 mysqlstub_select_db(MYSQL *mysql, const char *db);
int		 mysqlstub_query(MYSQL *mysql, const char *q);
int		 mysqlstub_send_query(MYSQL *mysql, const char *q,
					 unsigned long length);
int		 mysqlstub_real_query(MYSQL *mysql, const char *q,
					unsigned long length);
MYSQL_RES *      mysqlstub_store_result(MYSQL *mysql);
MYSQL_RES *      mysqlstub_use_result(MYSQL *mysql);

void         mysqlstub_get_character_set_info(MYSQL *mysql,
                           MY_CHARSET_INFO *charset);


void
mysqlstub_set_local_infile_handler(MYSQL *mysql,
                               int (*local_infile_init)(void **, const char *,
                            void *),
                               int (*local_infile_read)(void *, char *,
							unsigned int),
                               void (*local_infile_end)(void *),
                               int (*local_infile_error)(void *, char*,
							 unsigned int),
                               void *);

void
mysqlstub_set_local_infile_default(MYSQL *mysql);

int		 mysqlstub_shutdown(MYSQL *mysql,
                                       enum mysql_enum_shutdown_level
                                       shutdown_level);
int		 mysqlstub_dump_debug_info(MYSQL *mysql);
int		 mysqlstub_refresh(MYSQL *mysql,
				     unsigned int refresh_options);
int		 mysqlstub_kill(MYSQL *mysql,unsigned long pid);
int		 mysqlstub_set_server_option(MYSQL *mysql,
						enum enum_mysql_set_option
						option);
int		 mysqlstub_ping(MYSQL *mysql);
const char *	 mysqlstub_stat(MYSQL *mysql);
const char *	 mysqlstub_get_server_info(MYSQL *mysql);
const char *	 mysqlstub_get_client_info(void);
unsigned long	 mysqlstub_get_client_version(void);
const char *	 mysqlstub_get_host_info(MYSQL *mysql);
unsigned long	 mysqlstub_get_server_version(MYSQL *mysql);
unsigned int	 mysqlstub_get_proto_info(MYSQL *mysql);
MYSQL_RES *	 mysqlstub_list_dbs(MYSQL *mysql,const char *wild);
MYSQL_RES *	 mysqlstub_list_tables(MYSQL *mysql,const char *wild);
MYSQL_RES *	 mysqlstub_list_processes(MYSQL *mysql);
int		 mysqlstub_options(MYSQL *mysql,enum mysql_option option,
				      const void *arg);
void		 mysqlstub_free_result(MYSQL_RES *result);
void		 mysqlstub_data_seek(MYSQL_RES *result,
					my_ulonglong offset);
MYSQL_ROW_OFFSET  mysqlstub_row_seek(MYSQL_RES *result,
						MYSQL_ROW_OFFSET offset);
MYSQL_FIELD_OFFSET  mysqlstub_field_seek(MYSQL_RES *result,
					   MYSQL_FIELD_OFFSET offset);
MYSQL_ROW	 mysqlstub_fetch_row(MYSQL_RES *result);
unsigned long *  mysqlstub_fetch_lengths(MYSQL_RES *result);
MYSQL_FIELD *	 mysqlstub_fetch_field(MYSQL_RES *result);
MYSQL_RES *      mysqlstub_list_fields(MYSQL *mysql, const char *table,
					  const char *wild);
unsigned long	 mysqlstub_escape_string(char *to,const char *from,
					    unsigned long from_length);
unsigned long	 mysqlstub_hex_string(char *to,const char *from,
                                         unsigned long from_length);
unsigned long  mysqlstub_real_escape_string(MYSQL *mysql,
					       char *to,const char *from,
					       unsigned long length);
void		 mysqlstub_debug(const char *debug);
unsigned int	 mysqlstub_thread_safe(void);
my_bool		 mysqlstub_embedded(void);
my_bool          mysqlstub_read_query_result(MYSQL *mysql);


MYSQL_STMT *  mysqlstub_stmt_init(MYSQL *mysql);
int  mysqlstub_stmt_prepare(MYSQL_STMT *stmt, const char *query,
                               unsigned long length);
int  mysqlstub_stmt_execute(MYSQL_STMT *stmt);
int  mysqlstub_stmt_fetch(MYSQL_STMT *stmt);
int  mysqlstub_stmt_fetch_column(MYSQL_STMT *stmt, MYSQL_BIND *bind_arg,
                                    unsigned int column,
                                    unsigned long offset);
int  mysqlstub_stmt_store_result(MYSQL_STMT *stmt);
unsigned long  mysqlstub_stmt_param_count(MYSQL_STMT * stmt);
my_bool  mysqlstub_stmt_attr_set(MYSQL_STMT *stmt,
                                    enum enum_stmt_attr_type attr_type,
                                    const void *attr);
my_bool  mysqlstub_stmt_attr_get(MYSQL_STMT *stmt,
                                    enum enum_stmt_attr_type attr_type,
                                    void *attr);
my_bool  mysqlstub_stmt_bind_param(MYSQL_STMT * stmt, MYSQL_BIND * bnd);
my_bool  mysqlstub_stmt_bind_result(MYSQL_STMT * stmt, MYSQL_BIND * bnd);
my_bool  mysqlstub_stmt_close(MYSQL_STMT * stmt);
my_bool  mysqlstub_stmt_reset(MYSQL_STMT * stmt);
my_bool  mysqlstub_stmt_free_result(MYSQL_STMT *stmt);
my_bool  mysqlstub_stmt_send_long_data(MYSQL_STMT *stmt,
                                          unsigned int param_number,
                                          const char *data,
                                          unsigned long length);
MYSQL_RES * mysqlstub_stmt_result_metadata(MYSQL_STMT *stmt);
MYSQL_RES * mysqlstub_stmt_param_metadata(MYSQL_STMT *stmt);
unsigned int  mysqlstub_stmt_errno(MYSQL_STMT * stmt);
const char * mysqlstub_stmt_error(MYSQL_STMT * stmt);
const char * mysqlstub_stmt_sqlstate(MYSQL_STMT * stmt);
MYSQL_ROW_OFFSET  mysqlstub_stmt_row_seek(MYSQL_STMT *stmt,
                                             MYSQL_ROW_OFFSET offset);
MYSQL_ROW_OFFSET  mysqlstub_stmt_row_tell(MYSQL_STMT *stmt);
void  mysqlstub_stmt_data_seek(MYSQL_STMT *stmt, my_ulonglong offset);
my_ulonglong  mysqlstub_stmt_num_rows(MYSQL_STMT *stmt);
my_ulonglong  mysqlstub_stmt_affected_rows(MYSQL_STMT *stmt);
my_ulonglong  mysqlstub_stmt_insert_id(MYSQL_STMT *stmt);
unsigned int  mysqlstub_stmt_field_count(MYSQL_STMT *stmt);

my_bool  mysqlstub_commit(MYSQL * mysql);
my_bool  mysqlstub_rollback(MYSQL * mysql);
my_bool  mysqlstub_autocommit(MYSQL * mysql, my_bool auto_mode);
my_bool  mysqlstub_more_results(MYSQL *mysql);
int  mysqlstub_next_result(MYSQL *mysql);
int  mysqlstub_stmt_next_result(MYSQL_STMT *stmt);
void  mysqlstub_close(MYSQL *sock);



/**
 * function pointers
 */



#endif
