*This project has been created as part of the 42 curriculum by mchrispe.*

# NetPractice

## Description

NetPractice is a networking project from the 42 curriculum. The goal is to solve 10 progressively complex networking exercises by correctly configuring TCP/IP addresses, subnet masks, and default gateways on simulated network diagrams. Each level presents a broken network that must be repaired by filling in the missing or incorrect configuration fields until all devices can communicate properly.

The networks are entirely simulated and run locally in a web browser — no real infrastructure is involved.

---

## Instructions

### Running the training interface

1. Download the project archive from the 42 project page.
2. Extract the files into a folder of your choice.
3. Run the launch script:

```bash
bash run.sh
```

This will start a local web server and open the interface in your browser automatically.

> If `run.sh` doesn't work, you can start the server manually:
> ```bash
> python3 -m http.server 49242
> ```
> Then open your browser and navigate to `http://localhost:49242`.

### Using the interface

- Enter your **42 login** (`mchrispe`) in the login field to load your personal configuration.
- Alternatively, use the **evaluation** tab to generate a random configuration for practice or peer evaluation.
- For each level, modify the unshaded fields until the network is correctly configured.
- Use the **[Check again]** button to verify your configuration.
- Once a level is complete, click **[Get my config]** to export your configuration file.

### Submitting

- Complete all **10 levels** and export one configuration file per level using **[Get my config]**.
- Place all **10 exported files** at the **root of your Git repository**.
- Make sure your login was entered in the interface before exporting — it is embedded in the config files.

---

## Resources

### Networking concepts studied

- **TCP/IP addressing** — how IP addresses are structured and assigned
- **Subnet masks** — how to determine which part of an address is the network vs. the host
- **CIDR notation** — shorthand for expressing subnet masks (e.g. `/24`)
- **Default gateways** — how devices route traffic outside their local network
- **Routers** — devices that forward packets between different networks
- **Switches** — devices that connect devices within the same network
- **Routing** — how packets find their path across a network

### References

- [Subnet Calculator](https://www.subnet-calculator.com/) — useful for verifying subnet calculations
- [Wikipedia — Classless Inter-Domain Routing](https://en.wikipedia.org/wiki/Classless_Inter-Domain_Routing) — explanation of CIDR and subnetting

### AI usage

Claude (Anthropic) was used during this project to:
- Assist with writing this README