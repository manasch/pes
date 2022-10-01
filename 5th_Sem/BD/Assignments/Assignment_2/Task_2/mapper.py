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
    p_dot_q = 0
    norm_p = 0
    norm_q = 0

    # n = len(page_embeddings[str(p)])
    # kernel = 3
    # bound = n - kernel + 1

    i = 0

    if cache is None:
        p_dot_q += page_embeddings[str(p)][i] * page_embeddings[str(q)][i]
        p_dot_q += page_embeddings[str(p)][i + 1] * page_embeddings[str(q)][i + 1]
        p_dot_q += page_embeddings[str(p)][i + 2] * page_embeddings[str(q)][i + 2]
        p_dot_q += page_embeddings[str(p)][i + 3] * page_embeddings[str(q)][i + 3]
        p_dot_q += page_embeddings[str(p)][i + 4] * page_embeddings[str(q)][i + 4]
        p_dot_q += page_embeddings[str(p)][i + 5] * page_embeddings[str(q)][i + 5]

        norm_p += page_embeddings[str(p)][i] * page_embeddings[str(p)][i]
        norm_p += page_embeddings[str(p)][i + 1] * page_embeddings[str(p)][i + 1]
        norm_p += page_embeddings[str(p)][i + 2] * page_embeddings[str(p)][i + 2]
        norm_p += page_embeddings[str(p)][i + 3] * page_embeddings[str(p)][i + 3]
        norm_p += page_embeddings[str(p)][i + 4] * page_embeddings[str(p)][i + 4]
        norm_p += page_embeddings[str(p)][i + 5] * page_embeddings[str(p)][i + 5]

        norm_q += page_embeddings[str(q)][i] * page_embeddings[str(q)][i]
        norm_q += page_embeddings[str(q)][i + 1] * page_embeddings[str(q)][i + 1]
        norm_q += page_embeddings[str(q)][i + 2] * page_embeddings[str(q)][i + 2]
        norm_q += page_embeddings[str(q)][i + 3] * page_embeddings[str(q)][i + 3]
        norm_q += page_embeddings[str(q)][i + 4] * page_embeddings[str(q)][i + 4]
        norm_q += page_embeddings[str(q)][i + 5] * page_embeddings[str(q)][i + 5]

        # i += kernel

        cache = norm_p
    else:
        p_dot_q += page_embeddings[str(p)][i] * page_embeddings[str(q)][i]
        p_dot_q += page_embeddings[str(p)][i + 1] * page_embeddings[str(q)][i + 1]
        p_dot_q += page_embeddings[str(p)][i + 2] * page_embeddings[str(q)][i + 2]
        p_dot_q += page_embeddings[str(p)][i + 3] * page_embeddings[str(q)][i + 3]
        p_dot_q += page_embeddings[str(p)][i + 4] * page_embeddings[str(q)][i + 4]
        p_dot_q += page_embeddings[str(p)][i + 5] * page_embeddings[str(q)][i + 5]

        norm_q += page_embeddings[str(q)][i] * page_embeddings[str(q)][i]
        norm_q += page_embeddings[str(q)][i + 1] * page_embeddings[str(q)][i + 1]
        norm_q += page_embeddings[str(q)][i + 2] * page_embeddings[str(q)][i + 2]
        norm_q += page_embeddings[str(q)][i + 3] * page_embeddings[str(q)][i + 3]
        norm_q += page_embeddings[str(q)][i + 4] * page_embeddings[str(q)][i + 4]
        norm_q += page_embeddings[str(q)][i + 5] * page_embeddings[str(q)][i + 5]
    
    sim = p_dot_q / (cache + norm_q - p_dot_q)
    return [sim, cache]

for line in sys.stdin:
    line_split = line.strip().split(maxsplit=1)
    src = int(line_split[0])
    adj_nodes = [int(x) for x in line_split[1].strip('[]').split(',')]
    print(src, "{:2f}".format(float(0)))

    cache = None
    for node in adj_nodes:
        sim, cache = similarity(src, node, cache)
        contrib = (ranks[str(src)] * sim) / len(adj_nodes)
        print(node, contrib)
