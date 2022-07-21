import raftos
import asyncio

PORT = 8002
NODE_ID = 3
TASK_NO = 2
other_nodes = [i for i in [8000, 8001, 8002] if i != PORT]


raftos.configure({
        'log_path': './',
        'serializer': raftos.serializers.JSONSerializer
})

loop = asyncio.get_event_loop()


loop.create_task(
    raftos.register(
        # node running on this machine
        f'127.0.0.1:{PORT}',

        # other servers
        cluster=[
            f'127.0.0.1:{other_nodes[0]}',
            f'127.0.0.1:{other_nodes[1]}'
        ]
    )
)

with open(f'task{TASK_NO}_node{NODE_ID}.txt', 'w') as f:
    pass


async def run(loop):
    while raftos.get_leader() != f'127.0.0.1:{PORT}':
        await asyncio.sleep(10)

        with open(f'task{TASK_NO}_node{NODE_ID}.txt', 'a') as f:
            leader = raftos.get_leader()
            f.write(f'LEADER => {leader}\n')

    with open(f'task{TASK_NO}_node{NODE_ID}.txt', 'a') as f:
        f.write(f"LEADER IS NOW NODE {NODE_ID}\n")


loop.run_until_complete(run(loop))
loop.run_forever()
