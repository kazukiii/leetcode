class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        unique_emails = set()
        for email in emails:
            local_name, domain_name = email.split('@')
            unique_emails.add((
                self.clean_local_name(local_name),
                domain_name,
            ))

        return len(unique_emails)

    def clean_local_name(self, local_name):
        return self.remove_all_dots(self.remove_after_plus(local_name))

    def remove_all_dots(self, text):
        return text.replace('.', '')

    def remove_after_plus(self, text):
        return text.split('+')[0]
