# Homomorphic-Encryption

In this project a smart mobility environment is going to be simulated. One important part of the project is the hiding user specific data from 
third parties like cloud environments. For this purpose Microsoft SEAL is being used and we are encrypting the user_id before sending it to the cloud. It is the 
only user specific information that is shared with the cloud environment. For the invoicing process we have to send the user specific data inevitably.

In the Main.cpp we have basically two demos. The first one simulates the above described process and the second one shows us how to use Microsoft SEAL to encrypt a
std::uint64_t and do other computations on it.
