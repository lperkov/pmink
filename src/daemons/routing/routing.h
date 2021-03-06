/*
 * This file is part of Project MINK <http://www.release14.org>.
 *
 * Copyright (C) 2012 Release14 Ltd.
 * http://www.release14.org/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef ROUTING_H_
#define ROUTING_H_

#include <daemon.h>
#include <r14p.h>
#include <r14p_stats.h>
#include <config.h>
#include <pmink_utils.h>
#include <antlr_utils.h>
#include <sstream>
#include <boost/regex.hpp>
#include <atomic.h>
#include <r14p_utils.h>
#include <config_r14p.h>
#include <r14p_stats.h>
#include <routingd_events.h>
#include "cfg_events.h"

// daemon name and description
#define DAEMON_TYPE		"routingd"
#define DAEMON_DESCRIPTION	"pMINK Routing daemon"
#define DAEMON_CFG_NODE		"pmink routing"

// routing daemon descriptor definition
class RoutingdDescriptor : public pmink::DaemonDescriptor {
public:
    // constructor
    RoutingdDescriptor(const char* _type, const char* _desc);
    // destructor
    ~RoutingdDescriptor();

    void process_arguements(int argc, char** argv);
    void print_help();
    void init_r14p();
    int init_config(bool _process_config = true);
    void init();
    void process_config();
    void terminate();

    // config daemons
    std::vector<std::string*> config_daemons;
    // r14p session
    r14p::R14PSession* r14ps;
    // R14P stats
    r14p::R14PStatsSession* r14p_stats;
    // cfgd activity flag
    pmink::Atomic<bool> cfgd_active;
    // config
    config::Config* config;
    // current cfg id
    unsigned char cfgd_id[16];
    // config auth user id
    config::UserId cfgd_uid;
    // config r14p client
    r14p::R14PClient* cfgd_r14pc;
    // hbeat
    r14p::HeartbeatInfo* hbeat;
    // R14P port
    int r14p_port;
    // extra options
    pmink_utils::VariantParamMap<uint32_t> extra_params;
    // cfg events
    WRRConfigMod wrr_mod_handler;


};




#endif /* ROUTING_H_ */
