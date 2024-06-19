class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        unique_emails = set()
        for email in emails:
            local_name, domain_name = email.split('@')
            formatted_local_name = local_name.replace('.', '').split('+')[0]
            unique_emails.add(formatted_local_name + '@' + domain_name)

        return len(unique_emails)
