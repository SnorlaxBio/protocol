#include <arpa/inet.h>

#include "../number.h"
#include "version6.h"
#include "../internet.h"
#include "../exterior/gateway.h"

#ifndef   RELEASE
extern void internet_protocol_version6_debug(FILE * stream, const uint8_t * datagram) {
    const internet_protocol_version6_t * internet = (internet_protocol_version6_t *) datagram;

    uint32_t prefix = ntohl(internet->prefix);

    fprintf(stream, "| internet version 6 ");
    fprintf(stream, "| %d ", internet_protocol_version_get(datagram));
    fprintf(stream, "| %02x ", internet_protocol_version6_traffic_class_get(prefix));
    fprintf(stream, "| %05x ", internet_protocol_version6_flow_label_get(prefix));
    fprintf(stream, "| % 6d ", ntohs(internet->length));
    fprintf(stream, "| % 3d ", internet->next);
    fprintf(stream, "| % 3d ", internet->limit);
    fprintf(stream, "| %04x:%04x:%04x:%04x:%04x:%04x:%04x:%04x ", ntohs(internet->source[0]),
                                                                  ntohs(internet->source[1]),
                                                                  ntohs(internet->source[2]),
                                                                  ntohs(internet->source[3]),
                                                                  ntohs(internet->source[4]),
                                                                  ntohs(internet->source[5]),
                                                                  ntohs(internet->source[6]),
                                                                  ntohs(internet->source[7]));
    fprintf(stream, "| %04x:%04x:%04x:%04x:%04x:%04x:%04x:%04x ", ntohs(internet->destination[0]),
                                                                  ntohs(internet->destination[1]),
                                                                  ntohs(internet->destination[2]),
                                                                  ntohs(internet->destination[3]),
                                                                  ntohs(internet->destination[4]),
                                                                  ntohs(internet->destination[5]),
                                                                  ntohs(internet->destination[6]),
                                                                  ntohs(internet->destination[7]));
    fprintf(stream, "|\n");

    switch(internet->next) {
        case protocol_number_exterior_gateway:      exterior_gateway_protocol_message_debug(stream, datagram);      break;
        default:                                    snorlaxdbg(false, true, "check", "");                           break;
    }

    
}
#endif // RELEASE

/**
 * @page        Internet Protocol, Version 6 Specification
 * 
 * @tableofcontents
 * 
 * @section     Introduction        1. Introduction
 * 
 * IP version 6 is a new version of the Internet Protocol (IP), designed as the successor to IP version 4 (IPv4). The changes from IPv4 to IPv6 fall
 * primarily into the following categories:
 * 
 * - Expand Addressing Capabilities
 * 
 * IPv6 increases the IP address size from 32 bits to 128 bits, to support more levels of addressing hierarchy, a much greater number of addressable nodes,
 * and simpler autoconfiguration of addresses. The scalabilitiy of multicast routing is improvded by adding a "scope" field to multicast addresses. And a new
 * type of address called an "anycast address" is defined; it is used to send a packet to any one of a group of nodes.
 * 
 * - Header Format Simplification
 * 
 * Some IPv4 header fields have been dropped or made optional, to reduce the common-case processing cost of packet handling and to limit the bandwidth cost of the IPv6 header.
 * 
 * - Improved Support for Extensions and Options
 * 
 * Changes in the way IP header options are encoded allows for more efficient forwarding, less stringent limits on the length of options, and greater flexibility for
 * introducing new options in the future.
 * 
 * - Flow Labeling Capability
 * 
 * A new capability is added to enable the labeling of sequences of packets that the sender requests to be treated in the network as a single flow.
 * 
 * - Authentication and Privacy Capabilities
 * 
 * Extensions to support authentication, data integrity, and (optional) data confidentially are specified for IPv6.
 * 
 * @section     Terminology     2. Terminology
 * 
 * node         a device that implements IPv6.
 * 
 * router       a node that forwards IPv6 packets not explicitly addressed to itself.
 * 
 * host         any node that is not a router.
 * 
 * upper layer  a protocol layer immediately above IPv6.
 * 
 * link         a communication facility or medium over which nodes can communicate at the link layer, i.e., the layer immediately below IPv6.
 * 
 * neighbors    nodes attached to the same link.
 * 
 * interface    a node's attchment to a link.
 * 
 * address      an IPv6-layer identifier for an interface or a set of interfaces.
 * 
 * packet       an IPv6 header plus payload.
 * 
 * link MTU     the maximum transmission unit, i.e., maximum packet size in octets, that can be conveyed over a link.
 * 
 * path MTU     the maximum link MTU of all the links in a path between a source node and a destination node.
 * 
 * > Note: it is possible for a device with multiple interfaces to be configured to forward non-self-destined packets arriving from some set (fewer than all) of its interfaces
 * > and discard non-self-destined packets arriving from its other interfaces. Such a device must obey the protocol requirements for routers when receiving packets from,
 * > and interacting with neighors over, the former (forwarding) interfaces. It must obey the protocol requirements for hosts when receiving packets from, and interacting with
 * > neighbors over, the latter (non-forwarding) interfaces.
 * 
 * @section     IPv6HeaderFormat    3. IPv6 Header Format
 * 
 * <img src="InternetProtocolVersion6_HeaderFormat.png">
 * 
 * Version      4-bit Internet Protocol Version number = 6.
 * 
 * Traffic Class    8 bit Traffic Class filed.
 * 
 * Flow Label   20-bit flow label.
 * 
 * Payload Length   16 bit unsigned integer. Length of the IPv6 payload, i.e., the rest of the packet following this IPv6 header, in octets.
 *                  Note that any extension headers present are considered part of the payload, i.e., included in the length count.
 * 
 * Next Header      8 bit selector. Identifies the type of header immediately following the IPv6 header. USes the same values as the IPv5 protocol field.
 * 
 * Hop Limit    8 bit unsigned integer. Decremented by 1 byt each node that forwards the packet. When forwarding, the packet is discarded if Hop Limit was
 *              zero when received of is decremented to zero. A node that is the destination of packet should not discard a packet with Hop Limit equal to zero;
 *              it should process the packet normally.
 * 
 * Source Address   128 bit address of the originator of the packet.
 * 
 * Destination Address      128 bit address of the intended recipient of the packet (possible not the ultimate recipient, if a Routing header is present).
 * 
 * @section     IPv6ExtensionHeaders    4. IPv6 Extension Headers
 * 
 * In IPv6, optional internet layer information is encoded in separate headers that may be placed between the IPv6 header and the upper layer header in a packet.
 * There is a small number of such extension headers, each one identified by a distinct Next Header value.
 * 
 * Extension headers are numbered from IANA IP Protocol numbers, the same values used for IPv4 and IPv6. When processing a sequence of Next Header values in a packet,
 * the first one that is not an extension header indicates that the next item in the packet is the corresponding upper-layer header. A special "No Next Header" value
 * is used if there is no upper-layer header.
 * 
 * Extension headers (except for the Hop-by-Hop Options header) are not processed, inserted, or deleted by any node along a packet's delivery path, until reaches the node
 * (or each of the set of nodes, in the case of multicast) identified in the Destination Address field of the IPv6 header.
 * 
 * The Hop-by-Hop Options header is not inserted of deleted, but may be examined or processed by any node along a packet's delivery path, until reaches the node
 * (or each of the set of nodes, in the case of multicast) identified in the Destination Address field of the IPv6 header. The Hop-by-Hop Options header, when present, must
 * immediately follow the IPv6 header. Its presence is indicated by the value zero in the Next Header feild of the IPv6 header.
 * 
 * > Note: While [Internet Protocol, Version 6 Specification](https://datatracker.ietf.org/doc/html/rfc2460) required that all nodes must examine and process the Hop-by-Hop
 * > Options header, it is now expected that nodes along a packet's delivery path only examine and process the Hop-by-Hop Options header if explicitly configured to do so.
 * 
 * At the destination node, normal demultiplexing on the Next Header field of the IPv6 header invokeds the module to process the first extension header, or the upper-layer
 * header if no extension header is present. The contents and semantics of each extension header determine whether or not to processed strictly in the order they appear in the packet;
 * a receiver must not, for example, scan through a packet looking for a particular kind of extension header and prcess that header prior to processing all preceding ones.
 * 
 * If, as a result of processing a header, the destination node is required to proceed to the next header but the Next Header value in the current header is unrecognized by the node,
 * it should discard the packet and send an ICMP Parameter Problem message to the source of the packet, with an ICMP Code value of 1 ("unrecognized Next Header type encountered") and
 * the ICMP Pointer field containing the offset of the unrecognized value within the original packet. The same action should be taken if a node encounters a Next Header value of zero
 * in any header other than an IPv6 header.
 * 
 * Each extension header is an integer multiple of 8 octets long, in order to retain 8-octet alignment for subsequent headers. Multi-octet fields within each extension header are
 * aligned on their natural boundaries, i.e., fields of width n octets are placed at an integer mutliple of n octets from the start of the header, for n = 1, 2, 4, or 8.
 * 
 * A full implementation of IPv6 includes implementation of the following extension headers:
 * 
 * - Hop-by-Hop Options
 * - Fragment
 * - Destination Options
 * - Routing
 * - Authentication
 * - Encapsulating Security Payload
 * 
 * @subsection  IPv6ExtensionHeaders_ExtensionHeaderOrder   4.1. Extension Header Order
 * 
 * When more than one extension header is used in the same packet, it is recommended that those headers appear in the following order:
 * 
 * - IPv6 header
 * - Hop-by-Hop Options header
 * - Destination Options header (note 1)
 * - Routing header
 * - Fragment header
 * - Authentication header (note 2)
 * - Encapsulating Security Payload header (note 2)
 * - Destination Options header (note 3)
 * - Upper-Layer header
 * 
 * > Note 1: for options to be processed by the first destination that appears in the IPv6 Destination Address field plus subsequent destinations listed in the Routing header.
 * >
 * > Note 2: additional recommendations regarding the relative order of the Authentication and Encapsulating Security Payload header are given in [IP Encapsulating Security Payload (ESP)](https://datatracker.ietf.org/doc/html/rfc4303).
 * >
 * > Note 3: for options to be processed only by the final destination of the packet.
 * 
 * Each extension header should occur at most once, except for the Destination Options header, which should occur at most twice (once before a Routing header and once before the upper-layer header).
 * 
 * If the upper-layer header is another IPv6 header (in the case of IPv6 being tunneled over or encapsulated in IPv6), it may be followed by its own extension headers, which are separately subject to the same ordering recommendations.
 * 
 * If and when other extension headers are defined, their ordering constraints relative to the above listed headers must be specified.
 * 
 * IPv6 nodes must accept and attempt to process extension headers in any order and occurring any number of times in the same packet, except for the Hop-by-Hop Options header, which is restricted to appear immediately after an IPv6 header only.
 * Nonetheless, it is strongly advised that sources of IPv6 packets adhere to the above recommended order until and unless subsequent specifications revise that recommendation.
 * 
 * @subsection  IPv6ExtensionHeaders_Options            4.2. Options
 * 
 * Two of the currently defined extension headers specified in this document -- the Hop-by-Hop Options header and the Destination Options header -- carry a variable number of "options" that are type-length-value encoded in the following format:
 * 
 * <img src="InternetProtocolVersion6_Option.png">
 * 
 * Option Type      8 bit identifier of the type of option.
 * 
 * Option Data Len  8 bit unsigned integer. Length of the Option Data field of this option, in octets.
 * 
 * Option Data      Variable length field. Option-Type-specific data.
 * 
 * The sequence of options within a header must be processed strictly in the order they appear in the header; a receiver must not, for example, scan through the header looking for a particular kind of option and process that option prior to 
 * processing all preceding ones:
 * 
 * The Option Type identifiers are internally encoded such that their highest-order 2 bits specify the action that must be taken if the processing IPv6 node doest not recognize the Option Type:
 * 
 * 00           skip over this option and continue processing the header.
 * 01           discard the packet.
 * 10           discard the packet and, regardless of whether or not the packet's Destination Address was a multicast address, send an ICMP Parameter Problem Code 2, message to the packet's Source Address, pointing to the unrecognized Option Type.
 * 11           discard the packet and, only if the packet's Destination Address was not a multicast address, send an ICMP Parameter Problem, Code 2, message to the packet's Source Address, pointing to the unrecognized Option Type.
 * 
 * The third-highest-order bit of the Option Type specifies whether of not the Option Data of the option can change en route to the packet's final destination. When an Authentication header is present in the packet, for any option whose data may 
 * change en route, its entire Option Data field must be treated as zero-valued octets when computing or verifying the packet's authenticating value.
 * 
 * 0            Option Data does not change en route
 * 1            Option Data may change en route
 * 
 * The three high-order bites described above are to be treated as part of the Option Type, not independent of the Option Type. That is, a particular option is identified by a full 8 bit Option Type, not just the low-order 5 bits of an Option Type.
 * 
 * The same Option Type numbering space is used for both the Hop-by-Hop Options header and the Destination Options Header. However, the specification of a particular option may restrict its use to only one of those two headers.
 * 
 * Individual options may have specific alignment requirements, to ensure that multi-octet values within Option Data feilds fall on natural boundaries. The alignment requirement of an option is specified using the notation `xn + y`, meaning the Option
 * Type must appear at an integer multiple of x octets from the start of the header, plus y octets. For example:
 * 
 * 2n           means any 2-octet offset from the start of the header.
 * 
 * 8n + 2       means any 8-octet offset from the start of the header, plus 2 octets.
 * 
 * There are two padding options that are used when necessary to align subsequent options and to pad out the containing header to a multiple of 8 octets in length. These padding options must be recognized by all IPv6 implementations:
 * 
 * Pad1 option (alignment requirement: none)
 * 
 * <img src="InternetProtocolVersion6_Option_Pad1.png">
 * 
 * > Note the format of the Pad1 option is a special case -- it does not have length and value fields.
 * 
 * The Pad1 option is used to insert 1 octet of padding into the Options area of a header. If more than one octet of padding is required, the PadN option, described next, should be used, rather than multiple Pad1 options.
 * 
 * PadN option (alignment requirement: none)
 * 
 * <img src="InternetProtocolVersion6_Option_PadN.png">
 * 
 * The PadN option is used to insert two or more octets of padding into the Options area of a header. For N octets of padding, the Option Data Len field contains the vale `N - 2`, and the Option Data consists of `N - 2` zero-valued octets.
 * 
 * @see         [RFC:8200 / Internet Protocol, Version 6 (IPv6) Specification](https://datatracker.ietf.org/doc/html/rfc8200)
 * @see         [RFC:4291 / IP Version 6 Addressing Architecture](https://datatracker.ietf.org/doc/html/rfc4291)
 * @see         [RFC:4443 / Internet Control Message Protocol for the Internet Protocol Version 6 Specification](https://datatracker.ietf.org/doc/html/rfc4443)
 * @see         [RFC:791 / Internet Protocol](https://datatracker.ietf.org/doc/html/rfc791)
 * @see         [Protocol Numbers](https://www.iana.org/assignments/protocol-numbers/protocol-numbers.xhtml)
 * @see         [Internet Protocol Version 6 (IPv6) Parameters](https://www.iana.org/assignments/ipv6-parameters/ipv6-parameters.xhtml)
 * @see         [RFC:4302 / IP Authentication Header](https://datatracker.ietf.org/doc/html/rfc4302)
 * @see         [RFC:4303 / IP Encapsulating Security Payload (ESP)](https://datatracker.ietf.org/doc/html/rfc4303)
 */