/* 
 * File: stk.h
 * 
 *  Copyright (C) 2014 SixTeam
 *  All Rights Reserved
 *
 */

#ifndef _STK_H_
#define _STK_H_

#ifdef WIN32
#include <windows.h>
#include <winsock2.h>
#endif

#ifdef _LINUX_
#include <errno.h>
#endif

#include <gtk/gtk.h>

#include "stklist.h"
#include "stkprotocol.h"
#include "stkclient.h"
#include "stkwidget.h"

//#define STK_GUI_DEBUG
#define LOGIN_STYLE_NEW

/*
 *********************************************
 *              stkui.c                  *
 *********************************************
 */
GtkWidget *stk_mainwin_create(void);
gboolean stk_window_exit(GtkWidget *widget, GtkStatusIcon *tray);
gboolean stk_window_exit2(GtkWidget *widget, GdkEventButton *event, GtkStatusIcon *tray);
void stk_screensize_get(ScreenSize *screensize);
GtkStatusIcon *stk_tray_create(GtkWidget *window);
void stk_loginwin_create(StkWidget *widgets);


/*
 *********************************************
 *              stkchat.c                  *
 *********************************************
 */
void stk_chat_request(GtkWidget *widget, stk_buddy *buddy);
void stk_voice_request(GtkWidget *widget, stk_buddy *buddy);
void stk_video_request(GtkWidget *widget, stk_buddy *buddy);
void stk_chatwin_show(GtkWidget *widget, stk_buddy *buddy);
gboolean stk_msg_send(GtkWidget *widget, stk_buddy *buddy);
void stk_msg_event(stk_buddy *buddy);


/*
 *********************************************
 *              stkpacket.c                  *
 *********************************************
 */
int stk_init_socket(void);
void stk_clean_socket(socket_t fd);
int stk_connect(client_config *config);
int stk_login(socket_t fd, char *buf, int max_len, unsigned int uid, char *password);
int stk_send_getprofile(socket_t fd, char *buf, int max_len, unsigned int uid, unsigned int n_uid, stk_buddy *buddy);
int stk_send_getbuddylist(socket_t fd, char *buf, int max_len, unsigned int uid);
int stk_send_msg(socket_t fd, char *buf, int max_len, char *data, int data_len, unsigned int uid, unsigned int n_uid);
int stk_recv_msg(client_config *client);


/*
 *********************************************
 *               stkbuddy.c                  *
 *********************************************
 */
stk_buddy *stk_find_buddy(unsigned int uid);
int stk_add_buddy(stk_buddy *buddy);
int stk_update_buddy(stk_buddy *buddy);
unsigned short stk_get_buddynum(void);
stk_buddy *stk_get_next(stk_buddy *buddy);



/*
 *********************************************
 *              stkutil.c                  *
 *********************************************
 */


/*
 *********************************************
 *              stkwav.c                  *
 *********************************************
 */
void stk_play_wav(char *filename);

#endif /* _STK_H_ */
