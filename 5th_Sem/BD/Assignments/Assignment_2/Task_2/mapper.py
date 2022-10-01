#!/usr/bin/env python3

import sys
import json

w_path = sys.argv[1]
page_embeddings_path = sys.argv[2]
ranks = {}

with open(w_path) as f, open(page_embeddings_path) as g:
    w = f.readlines()
    page_embeddings = json.load(g)

for rank in w:
    rank_split = rank.strip().split(',')
    ranks[rank_split[0]] = float(rank_split[1])

def similarity(p, q, cache):
    if cache is None:
        p_dot_q = sum([x*y for x,y in list(zip(page_embeddings[str(p)],page_embeddings[str(q)]))])
        norm_p = sum([x*y for x,y in list(zip(page_embeddings[str(p)],page_embeddings[str(p)]))])
        norm_q = sum([x*y for x,y in list(zip(page_embeddings[str(q)],page_embeddings[str(q)]))])

        cache = norm_p
    else:
        p_dot_q = sum([x*y for x,y in list(zip(page_embeddings[str(p)],page_embeddings[str(q)]))])
        norm_q = sum([x*y for x,y in list(zip(page_embeddings[str(q)],page_embeddings[str(q)]))])
    
    sim = p_dot_q / (cache + norm_q - p_dot_q)
    return [sim, cache]

for line in sys.stdin:
    line_split = line.strip().split(maxsplit=1)
    src = int(line_split[0])
    adj_nodes = [int(x) for x in line_split[1].strip('[]').split(',')]

    cache = None
    for node in adj_nodes:
        sim, cache = similarity(src, node, cache)
        contrib = (ranks[str(src)] * sim) / len(adj_nodes)
        print(node, contrib)
    