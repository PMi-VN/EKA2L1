/*
 * Copyright (c) 2020 EKA2L1 Team
 * 
 * This file is part of EKA2L1 project
 * (see bentokun.github.com/EKA2L1).
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
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <epoc/services/framework.h>
#include <epoc/services/server.h>

namespace eka2l1 {

    enum notifier_opcode {
        notifier_notify,
        notifier_info_print,
        notifier_start,
        notifier_cancel,
        notifier_update,
        notfiier_start_and_get_response,
        notifier_start_from_dll,
        notifier_start_from_dll_and_get_response,
        notifier_notify_cancel,
        notifier_update_and_get_response,
    };

    class notifier_server : public service::typical_server {
    public:
        explicit notifier_server(eka2l1::system *sys);

        void connect(service::ipc_context &context) override;
    };

    struct notifier_client_session : public service::typical_session {
        explicit notifier_client_session(service::typical_server *serv, const std::uint32_t ss_id, epoc::version client_version);

        void fetch(service::ipc_context *ctx) override;

    };
}
