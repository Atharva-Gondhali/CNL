#LEAKY BUCKET

import time
class LeakyBucket:
    def __init__(self, bucket_capacity, leak_rate):
        self.bucket_capacity = bucket_capacity  
        self.leak_rate = leak_rate              
        self.current_water = 0                  

    def add_packet(self, packet_size):
        if self.current_water + packet_size > self.bucket_capacity:
            print(f"Bucket overflow! Dropped {packet_size} units of data.")
        else:
            self.current_water += packet_size
            print(f"\nAdded {packet_size} units of data to the bucket. Current bucket level: {self.current_water}")

    def leak(self):
        if self.current_water > 0:
            self.current_water = max(0, self.current_water - self.leak_rate)
            print(f"Leaked {self.leak_rate} units of data. Current bucket level: {self.current_water}")
        else:
            print("Bucket is empty. Nothing to leak.")

    def simulate(self, packet_sizes, interval):
        for packet in packet_sizes:
            self.add_packet(packet)
            self.leak()
            time.sleep(interval)  

bucket_capacity = int(input("Enter bucket capacity: "))
leak_rate = int(input("Enter leak rate (units per second): "))

num_packets = int(input("Enter the number of packets: "))
packet_sizes = []
for i in range(num_packets):
    packet_size = int(input(f"Enter size of packet {i + 1}: "))
    packet_sizes.append(packet_size)

interval = int(input("Enter interval between packets (in seconds): "))

bucket = LeakyBucket(bucket_capacity, leak_rate)
bucket.simulate(packet_sizes, interval)

