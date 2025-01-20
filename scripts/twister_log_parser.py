import argparse
import json


def generate_github_step_summary(json_file, output_file):
    with open(json_file, "r") as file:
        data = json.load(file)

    summary_lines = []

    summary_lines.append("| Test Case | Execution Time | Status | Result |")
    summary_lines.append("|-----------|----------------|--------|--------|")

    for testsuite in data["testsuites"]:
        for testcase in testsuite["testcases"]:
            row = "| {} | {} | {} | {} |".format(
                testcase["identifier"],
                testcase["execution_time"],
                testcase["status"],
                ":white_check_mark:" if testcase["status"] == "passed" else ":x:",
            )
            summary_lines.append(row)

    with open(output_file, "w") as file:
        file.write("\n".join(summary_lines))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Generate Markdown file table from test results JSON file.",
    )
    parser.add_argument(
        "-i",
        "--input_file",
        default="twister.json",
        type=str,
        help="Path to the input JSON file",
        required=True,
    )
    parser.add_argument(
        "-o",
        "--output_file",
        default="GITHUB_STEP_SUMMARY.md",
        type=str,
        help="Path to the output markdown file",
    )

    args = parser.parse_args()

    generate_github_step_summary(args.input_file, args.output_file)
