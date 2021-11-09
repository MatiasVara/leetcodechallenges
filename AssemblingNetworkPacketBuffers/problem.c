/*
 * Assembling network packet buffers
 *
 * Many programs build network packets in multiple stages, making it difficult
 * to allocate a single memory buffer for the packet upfront.
 *
 * This exercise asks you to implement pktbuf_join(), a function that
 * concatenates two packet buffers without copying the payload. This function
 * allows programs to assemble the final packet from separately allocated
 * packet buffers. For example, TCP/IP headers can be joined with one or more
 * data buffers.
 *
 * Your task is to implement code marked with "TODO" comments below.
 */
 
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
 
/* TODO include C Standard Library headers if necessary */
#include <string.h>

/* Packet buffer - these can be assembled using pktbuf_join() */
struct pktbuf {
    void *data; /* packet payload */
    size_t len; /* length of @data in bytes */
    struct pktbuf * next;
    struct pktbuf * tail;
    /* TODO additional fields to support pktbuf_join() */
};
 
/**
 * pktbuf_create:
 * @data: packet payload
 * @len: length of @data in bytes
 *
 * Allocate and initialize a new struct pktbuf holding the given payload. This
 * function takes ownership of @data instead of copying its contents.
 *
 * Returns: a new struct pktbuf or NULL on error.
 */
struct pktbuf *pktbuf_create(void *data, size_t len)
{
    struct pktbuf *pkt = malloc(sizeof(*pkt));
    if (!pkt) {
        return NULL;
    }
 
    pkt->data = data;
    pkt->len = len;
    /* TODO initialize additional fields */
    pkt->next = NULL;
    pkt->tail = NULL;
    return pkt;
}
 
/**
 * pktbuf_destroy:
 * @pkt: the packet to destroy
 *
 * Deallocate @pkt and its payload.
 */
void pktbuf_destroy(struct pktbuf *pkt)
{
    struct pktbuf * pk = pkt;
    struct pktbuf * next;
    /* TODO free resources associated with @pkt */
    while (pk != NULL){
      next = pk->next;
      free(pk->data);
      free(pk);
      pk = next;
    }
}
 
/**
 * pktbuf_join:
 * @head: the first packet buffer
 * @tail: the second packet buffer
 *
 * Appends @tail to @head without copying its payload. pktbuf_join(head, foo)
 * and pktbuf_join(tail, bar) may have been previously called with other packet
 * buffers. This makes it possible to construct the desired packet layout with
 * a sequence of pktbuf_join() calls:
 *
 *   pktbuf_join(ipv4_header, tcp_header);
 *   pktbuf_join(ethernet_header, ipv4_header);
 *   pktbuf_join(ethernet_header, data);
 *
 * The resulting payload layout is:
 *
 *   1. ethernet_header
 *   2. ipv4_header
 *   3. tcp_header
 *   4. data
 *
 * This function takes ownership of @tail and the caller must not call
 * pktbuf_destroy(tail).
 *
 * Returns: true on success, false on error.
 */
bool pktbuf_join(struct pktbuf *head, struct pktbuf *tail)
{
    /*
     * TODO implement this function
     *
     * Note: pick a simple data structure since you have 30 minutes for this
     * exercise.
     */
     if ((head->next == NULL) && (head->tail== NULL)){
       head->next = tail;
       head->tail = tail;
       //tail->next = NULL;
       return true;
     }
     head->tail->next = tail;
     head->tail = tail;
     return true;
}
 
/**
 * pktbuf_copy_out:
 * @pkt: the source packet buffer
 * @out: the destination memory buffer
 * @outlen: the size of @out in bytes
 *
 * Copy up to @outlen bytes from the packet buffer @pkt into the memory buffer
 * @out.
 *
 * Returns: the number of bytes copied.
 */
size_t pktbuf_copy_out(struct pktbuf *pkt, void *out, size_t outlen)
{
    struct pktbuf * buf = pkt;
    int count = 0;
    int ret = 0;
    /* TODO */
    while ((pkt != NULL)&& (outlen >0)){
      count = pkt->len;
      if (count >= outlen){
        count = outlen;
      }
      memcpy(out,pkt->data, count);
      out += count;
      ret += count;
      outlen -= count;
      pkt = pkt->next;
    }
    return ret;
}
 
/* Test cases - reading code below this line is not necessary */
int main(int argc, char **argv)
{
    void *payload_a;
    void *payload_b;
    void *payload_c;
    struct pktbuf *a;
    struct pktbuf *b;
    struct pktbuf *c;
    char out[4]; /* one more byte than needed to test pktbuf_copy_out() */
 
    /* Join a and b, then c */
    assert((payload_a = strdup("a")));
    assert((a = pktbuf_create(payload_a, 1)));
    assert((payload_b = strdup("b")));
    assert((b = pktbuf_create(payload_b, 1)));
    assert((payload_c = strdup("c")));
    assert((c = pktbuf_create(payload_c, 1)));
 
    assert(pktbuf_copy_out(a, out, sizeof(out)) == 1);
    assert(out[0] == 'a');
    assert(pktbuf_copy_out(b, out, sizeof(out)) == 1);
    assert(out[0] == 'b');
    assert(pktbuf_copy_out(c, out, sizeof(out)) == 1);
    assert(out[0] == 'c');
 
    assert(pktbuf_join(a, b));
    assert(pktbuf_copy_out(a, out, sizeof(out)) == 2);
    assert(out[0] == 'a');
    assert(out[1] == 'b');
 
    /* pktbuf_copy_out() with a larger output memory buffer */
    assert(pktbuf_join(a, c));
    assert(pktbuf_copy_out(a, out, sizeof(out)) == 3);
    assert(out[0] == 'a');
    assert(out[1] == 'b');
    assert(out[2] == 'c');
 
    /* pktbuf_copy_out() with an exactly sized output memory buffer */
    memset(out, 0, sizeof(out));
    assert(pktbuf_copy_out(a, out, 3) == 3);
    assert(out[0] == 'a');
    assert(out[1] == 'b');
    assert(out[2] == 'c');
 
    /* pktbuf_copy_out() with a short output memory buffer */
    memset(out, 0, sizeof(out));
    assert(pktbuf_copy_out(a, out, 1) == 1);
    assert(out[0] == 'a');
 
    pktbuf_destroy(a);
 
    /* Join b and c, then a */
    assert((payload_a = strdup("a")));
    assert((a = pktbuf_create(payload_a, 1)));
    assert((payload_b = strdup("b")));
    assert((b = pktbuf_create(payload_b, 1)));
    assert((payload_c = strdup("c")));
    assert((c = pktbuf_create(payload_c, 1)));
 
    memset(out, 0, sizeof(out));
    assert(pktbuf_copy_out(a, out, sizeof(out)) == 1);
    assert(out[0] == 'a');
    assert(pktbuf_copy_out(b, out, sizeof(out)) == 1);
    assert(out[0] == 'b');
    assert(pktbuf_copy_out(c, out, sizeof(out)) == 1);
    assert(out[0] == 'c');
 
    assert(pktbuf_join(b, c));
    assert(pktbuf_copy_out(b, out, sizeof(out)) == 2);
    assert(out[0] == 'b');
    assert(out[1] == 'c');

    // TODO:the tail in a should point to c ?
    assert(pktbuf_join(a, b));
    assert(pktbuf_copy_out(a, out, sizeof(out)) == 3);
    assert(out[0] == 'a');
    assert(out[1] == 'b');
    assert(out[2] == 'c');
 
    pktbuf_destroy(a);
 
    return 0;
}
