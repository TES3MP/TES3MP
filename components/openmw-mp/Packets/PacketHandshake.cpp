//
// Created by koncord on 28.04.16.
//

#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketHandshake.hpp"

using namespace mwmp;

PacketHandshake::PacketHandshake(RakNet::RakPeerInterface *peer) : BasePacket(peer)
{
    packetID = ID_HANDSHAKE;
}

void PacketHandshake::Packet(RakNet::BitStream *bs, BasePlayer *player, bool send)
{
    BasePacket::Packet(bs, player, send);
    RW(player->Npc()->mName, send);
    RW(*player->GetPassw(), send);
}
